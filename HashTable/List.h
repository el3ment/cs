
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#pragma once

template <typename ItemType>
class List {

	
	public :
		
	class Node{
	public :
		ItemType item;
		Node* next;
		Node(const ItemType& item){
			this->item = item;
			this->next = NULL;
		}
	};
	
	Node* head;
	int size;

	List(){
		this->head = NULL;
		this->size = 0;
	}
	~List(){
		removeAll(this->head);
		this->head = NULL;
	}
	
	void removeAll(Node* node){
		if(node != NULL){
			removeAll(node->next);
			node->next = NULL;
			delete node;
		}
	}
	
	Node* add(Node* node, const ItemType& item){
		if(node != NULL){
			if(node->item != item){
				node->next = this->add(node->next, item);
			}
		}else{
			this->size++;
			return new Node(item);
		}
		
		return node;
	}
	
	bool add(const ItemType& item) {
		int temp = this->size;
		
		this->head = this->add(this->head, item);
		
		return temp != this->size;
	}

	bool remove(const ItemType& item) {
            bool rtn = false;
		Node* node = this->head;
		Node* prev = NULL;
		while(node != NULL){
			if(node->item == item)
				break;
			prev = node;
			node = node->next;
		}
		if(node != NULL){
			if(prev != NULL)
				prev->next = node->next;
			else{
				this->head = NULL;
				this->head = node->next;
			}
			this->size--;
                        rtn = true;
			delete node;
			
		}
                
                return rtn;

	}

	bool find(const ItemType& item) {
		
		Node* node = this->head;
		while(node != NULL){
			if(node->item == item)
				return true;
			node = node->next;
		}
		
		return false;

	}
	
	string print(){
		stringstream output;
		Node* node = this->head;
		while(node != NULL){
			output << node->item << " ";
			node = node->next;
		}
		return output.str();
	}


};

