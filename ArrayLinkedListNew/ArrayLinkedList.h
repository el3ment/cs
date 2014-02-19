#pragma once

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 2;  

template <typename ItemType>

class LinkedArrayList {

	class Node {
	  public:
		  ItemType* items;
		  Node* next;
		  Node* prev;
		  int capacity;
		  int size;

		  Node(int capacity)
		  : items(new ItemType[capacity]){
			  this->capacity = capacity;
			  this->size = 0;
			  this->next = NULL;
			  this->prev = NULL;
		  }
		  virtual ~Node(){
			  delete[] items;
		  }
	};
	
	class _FoundNode{
	  public :
		Node* node;
		int sizeToLeft;
		int adjustedIndex;
	};
  
  private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
	
	_FoundNode findNodeAt(int index){
		
		//cout << "alrighty - trying to find index : "<<index<<endl;
		//cout << this->print();
		
		_FoundNode foundNodeStruct;
		bool findFromRight = false;
		Node* n = this->head;
		Node* foundNode = NULL;
		int totalSize = 0;
		
		if(index > this->size / 2){
			findFromRight = true;
                        n = this->tail;
			totalSize = this->size;
		}
		
		while(foundNode == NULL && n != NULL){
			if(findFromRight){
				totalSize -= n->size;
				if(index >= totalSize){
					foundNode = n;
				}else{
					n = n->prev;
				}
			}else{
				totalSize += n->size;
			
				if(index <= totalSize){
					foundNode = n;
				}else{
					n = n->next;
				}
			}
		}
		if(findFromRight){ // make it work like findfromleft
			totalSize += foundNode->size;
		}
		
		foundNodeStruct.node = foundNode;
		foundNodeStruct.sizeToLeft = totalSize;
		foundNodeStruct.adjustedIndex = index - (totalSize - n->size);
		
		// This is dumb.
		if(foundNodeStruct.node->next != NULL && index == foundNodeStruct.sizeToLeft){
			foundNodeStruct.node = foundNodeStruct.node->next;
			foundNodeStruct.sizeToLeft += foundNodeStruct.node->size;
		}
		
		return foundNodeStruct;
	}
    
  public:
    
    // Constructors and Destructors
    LinkedArrayList(int capacity){
      if(capacity > 0 && capacity % 2 == 0){
          this->capacity = capacity;
      }
	  this->size = 0;
	  this->head = NULL;
      /* What happens here if it's negative or if it's odd? */
    }
    LinkedArrayList(){};
    LinkedArrayList(const LinkedArrayList& orig){};
    virtual ~LinkedArrayList(){
		Node* next;
		Node* n = this->head;
		while(n != NULL){
			next = n->next;
			delete n;
			n = next;
		}
	};
	
    // Public Methods
    void insert(int index, const ItemType& item) {
		if(index < 0 || index > this->size){
			return;
		}
		if(this->size == 0){
			this->head = new Node(this->capacity);
			this->tail = this->head;
		}
		_FoundNode foundNode = findNodeAt(index);
	
		if(foundNode.node->size == foundNode.node->capacity){
            splitNodeAt(foundNode.node); // The node is full, create a new node
			foundNode.sizeToLeft -= foundNode.node->next->size;
			
			// We've split the node, and we need to pick the right one to insert into
			// and readjust nodeIndex and totalSize to match
			if(index >= foundNode.sizeToLeft){
				foundNode.node = foundNode.node->next;
				foundNode.sizeToLeft += foundNode.node->size;

			}
		}

		// Shift items
        int adjustedIndex = index - (foundNode.sizeToLeft - foundNode.node->size);
		for(int i = foundNode.node->size - 1; i > adjustedIndex - 1; i--){
			foundNode.node->items[i+1] = foundNode.node->items[i];
        }
       
        // Add item, and increase size
		foundNode.node->items[adjustedIndex] = item;
        foundNode.node->size++;
		this->size++;
    }
	
	void splitNodeAt(Node* indexedNode){
		Node* newNode = createNodeAt(indexedNode);
		int total = indexedNode->size;
		for(int i = total / 2; i < total; i++){
			newNode->items[i - (total / 2)] = indexedNode->items[i];
			indexedNode->size--;
			newNode->size++;
		}
		if(indexedNode == this->tail){
			this->tail = newNode;
		}
		
	}
    
    Node* createNodeAt(Node* indexedNode){
        
		Node* newNode = new Node(indexedNode->capacity);
		
		newNode->next = indexedNode->next;
        newNode->prev = indexedNode;
		if(indexedNode->next)
			indexedNode->next->prev = newNode;
		
		indexedNode->next = newNode;
		
        return newNode;
    }
	
void removeNode(Node* nodeToRemove){
		if(nodeToRemove->next != NULL){
			nodeToRemove->next->prev = nodeToRemove->prev;
                }else{
                    this->tail = nodeToRemove->prev;
                }
		if(nodeToRemove->prev != NULL){
			nodeToRemove->prev->next = nodeToRemove->next;
		}else{
			this->head = nodeToRemove->next;
		}
		delete nodeToRemove;
	}

    ItemType remove(int index) {
		
		if(index > this->size){
			index = this->size - 1; // if requested an out of bound index, insert onto end
			return ItemType();
		}else if(index < 0){
			return ItemType();
		}
		
		_FoundNode foundNode = findNodeAt(index);
		
		int adjustedIndex = index - (foundNode.sizeToLeft - foundNode.node->size);
		ItemType temp = foundNode.node->items[adjustedIndex];

		for(int i = adjustedIndex; i < foundNode.node->size - 1; i++){
			foundNode.node->items[i] = foundNode.node->items[i+1];
		}
		foundNode.node->size--;
		this->size--;
		
		if(foundNode.node->size == 0){
			this->removeNode(foundNode.node);
		}

		return temp;
		
		//return ItemType();
    }

    int find(const ItemType& item) {
		
		Node* n = this->head;
		int index = 0;
		while(n != NULL){
			for(int i = 0; i < n->size; i++){
				if(item == n->items[i]){
					return index;
				}
				index++;
			}
			n = n->next;
		};
		
		return -1;

    }

    string print(){
        stringstream output;
        
        Node* n = this->head;
        int nodeIndex = 1;
		while(n != NULL){
			output << "node " << nodeIndex -1 << ": ";
			for(int i = 0; i < n->size; i++){
				output << n->items[i] << " ";
			}
			output << endl;
			nodeIndex++;
			n = n->next;
		};
		
        return output.str();
    }


};