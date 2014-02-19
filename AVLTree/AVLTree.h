#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <typename ItemType>

class AVLTreeSet{

	public:

	class Node {
	public:
	  ItemType item;
	  Node* parent;
	  Node* left;
	  Node* right;
	  int height;
	  Node(const ItemType& item){
		  this->parent = NULL;
		  this->item = item;
		  this->left = NULL;
		  this->right = NULL;
		  this->height = 1;
	  }
	};

	Node* root;
	int size;

	AVLTreeSet(){
		this->root = NULL;
	}
	~AVLTreeSet(){
		this->removeAll(this->root);
	}

	void removeAll(Node* start){
	  if(start != NULL){
		  this->removeAll(start->right);
		  this->removeAll(start->left);
		  this->remove(start, false);
	  }
	}

	Node* rotateLeft(Node* node){
	  Node *otherNode;

		  otherNode = node->right;
		  otherNode->parent = node->parent;
		  if(otherNode->parent == NULL)
			  this->root = otherNode;
		  node->right = otherNode->left;
		  if(otherNode->left != NULL)
			  otherNode->left->parent = node;
		  node->parent = otherNode;
		  otherNode->left = node;
		
		  if(otherNode->parent != NULL){
			  if(otherNode->parent->right == node)
				  otherNode->parent->right = otherNode;
			  else
				  otherNode->parent->left = otherNode;
		  }
		  updateHeights(node);
		  updateHeights(otherNode);

		  return otherNode;
	}

	Node* rotateRight(Node* node){
		Node *otherNode;

		  otherNode = node->left;
		  otherNode->parent = node->parent;
		  if(otherNode->parent == NULL)
			  this->root = otherNode;
		  node->left = otherNode->right;
		  if(otherNode->right != NULL)
			  otherNode->right->parent = node;
		  node->parent = otherNode;
		  otherNode->right = node;
		  if(otherNode->parent != NULL){
			  if(otherNode->parent->right == node)
				  otherNode->parent->right = otherNode;
			  else
				  otherNode->parent->left = otherNode;
		  }
			  
		  

		  updateHeights(node);
		  updateHeights(otherNode);

		  return otherNode;
	}
	Node* leftRight(Node* node){
		int leftRight = (node->left != NULL && node->left->right != NULL) ? node->left->right->height : 0;
		int leftLeft = (node->left != NULL && node->left->left != NULL) ? node->left->left->height : 0;
		
		if(leftRight - leftLeft >= 1){ // If left subtree is right heavy
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}else{
		   return rotateRight(node); 
		}
	}
	Node* rightLeft(Node* node){
		int rightRight = (node->right != NULL && node->right->right != NULL) ? node->right->right->height : 0;
		int rightLeft = (node->right != NULL && node->right->left != NULL) ? node->right->left->height : 0;

		if(rightLeft - rightRight >= 1){ // If right subtree is left heavy
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}else{
			return rotateLeft(node);
		}
	}
	Node* balance(Node* node){
		int left = (node->left != NULL) ? node->left->height : 0;
		int right = (node->right != NULL) ? node->right->height : 0;

		
		if(left - right >= 2){
			return leftRight(node);
			
		}else if(right - left >= 2){
			return rightLeft(node);
		}

		return node;
	}

	Node* add(Node* node, const ItemType& item){
	  if(node == NULL)
		  return new Node(item);

	  if(item < node->item){
		  if(node->left == NULL)
			  node->height++;
		  node->left = this->add(node->left, item);
		  node->left->parent = node;
	  }else if(item > node->item){
		  if(node->right == NULL)
			  node->height++;
		  node->right = this->add(node->right, item);
		  node->right->parent = node;
	  }

	  this->updateHeights(node);
	  node = this->balance(node);


	  return node;

	}

	/*void updateHeights(Node* node, bool isRecursive){
		if(isRecursive){
			if(node->right != NULL)
			  this->updateHeights(node->right, true);
			if(node->left != NULL)
			  this->updateHeights(node->left, true);

			this->updateHeights(node);
		}
	}*/

	void updateHeights(Node* node){
		if(node->right != NULL){
			if(node->left != NULL){
				node->height = max(node->right->height, node->left->height) + 1;
			}else{
				node->height = node->right->height + 1;
			}
		}else if(node->left != NULL){
			node->height = node->left->height + 1;
		}else{
			node->height = 1;
		}
	}

	void add(const ItemType& item){
		this->root = this->add(this->root, item);
	}

	Node* findSmallestChild(Node* node){
		if(node == NULL)
			return node;

		if(node->left != NULL){
			return findSmallestChild(node->left);
		}else{
			return node;
		}

	}

	void removeFromTree(Node* node){
		bool isRoot = node->parent == NULL;
		bool isRightNode = !isRoot ? node->parent->right == node : false;

		if(!isRoot){
			if(isRightNode){
				if(node->left != NULL){
					node->parent->right = node->left;
					node->left->parent = node->parent;
				}else{
					node->parent->right = node->right;
					if(node->right != NULL)
						node->right->parent = node->parent;
				}
			}else{
				if(node->left != NULL){
					node->parent->left = node->left;
					node->left->parent = node->parent;
				}else{
					node->parent->left = node->right;
					if(node->left != NULL)
						node->right->parent = node->parent;
				}
			}

		}else{
		  if(node->left != NULL){
			this->root = node->left;
			node->left->parent = NULL;
		  }else{
			  this->root = NULL;
		  }
		}
	}
	
	void remove(Node* node, bool rebalanceAfterDelete = true){

		if(node != NULL){
			
			Node* smallestNode = this->findSmallestChild(node->right);
			if(smallestNode != NULL){
				node->item = smallestNode->item;
				this->remove(smallestNode);
			}else{
				
				this->removeFromTree(node);
				
				Node* temp = node;

				while(temp->parent != NULL){
					temp = temp->parent;
					this->updateHeights(temp);
					if(rebalanceAfterDelete){
					  temp = this->balance(temp);
					}
					
				}
				//cout << node->item;
				
				delete node;

			}
		}
	}

	void remove(const ItemType& item){
		this->remove(this->find(this->root, item));
	}
  
	Node* find(Node* start, const ItemType& item){
		if(start == NULL){
			return start;
		}else if(start->item == item){
			return start;
		}else if(item < start->item){
			return this->find(start->left, item);
		}else{
			return this->find(start->right, item);
		}
	}

	bool find(const ItemType& item) {
	  return (this->find(this->root, item) != NULL);
	}

	string printGivenLevel(struct Node* node, int level)
	{
		stringstream output;

		if(node == NULL)
			return "";
		if(level <= 0){
			output << node->item << "(" << node->height << ")";
		}else if(level > 0){
			string left = printGivenLevel(node->left, level-1);
			string right = printGivenLevel(node->right, level-1);
			output << left << ((left.size() > 1 && (right.size() > 1)) ? " " : "");
			output << right;
		}

		return output.str();
	}
  
	void printInline(Node* node){
		if(node != NULL){
			cout << "[" << (node->parent != NULL ? node->parent->item : "root") << "-" << (node->left != NULL ? "true" : "false") << "-" << (node->right != NULL ? "true" : "false") << "]" << node->item << "(" << node->height << ") ";
			printInline(node->left);
			printInline(node->right);
		}
	}
	
	string print(){
		stringstream output;
		if(this->root != NULL){
			for(int i = 0; i < this->root->height; i++){
				stringstream level(printGivenLevel(this->root, i));
				string leaf;
				int count = 0;
				while(level >> leaf){
					if(count % 8 == 0)
						output << endl << "level " << i << ": ";
					
					output << leaf << " ";
					count++;
				}
			}
			
			//cout << endl;
			//printInline(this->root);
			//cout << endl;
		
		}
		output << endl;
		return output.str();
	}

};