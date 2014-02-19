
#include "List.h"
#include "sstream"
#pragma once

template <typename ItemType>

class HashSet {

	public :
	
	List<ItemType>* table;
	int tableSize;
	int size;
	
	HashSet(){
		this->table = new List<ItemType>[1]();
		this->tableSize = 1;
		this->size = 0;
	}
	~HashSet(){
		delete[] this->table;
		this->table = NULL;
	}

	void grow(){

		int oldSize = this->tableSize;
		this->tableSize *= 2;
		this->tableSize += 1;
		this->size = 0;

		List<ItemType>* tempTable = this->table;
		this->table = new List<ItemType>[this->tableSize]();
		
		for(int i = 0; i < oldSize; i++){
			List<string>::Node* current = tempTable[i].head;
			while(current != NULL){
				this->add(current->item);
				current = current->next;
			}
		}
		
		delete[] tempTable;
		
	}
	
	void shrink(){
		int oldSize = this->tableSize;
		this->tableSize /= 2;
		this->size = 0;

		List<ItemType>* tempTable = this->table;
		this->table = new List<ItemType>[this->tableSize];
		
		for(int i = 0; i < oldSize; i++){
			List<string>::Node* current = tempTable[i].head;
			while(current != NULL){
				this->add(current->item);
				current = current->next;
			}
		}
		
		delete[] tempTable;
	}
	
	unsigned hash(string item){
		unsigned index = 0;
		
		for(unsigned int i = 0; i < item.size(); i++){
			index  *= 31;
			index += item[i];
		}
                
                return index % this->tableSize;
	}
	
	void add(const ItemType& item) {
		if(this->size >= this->tableSize){
                    if(this->tableSize > 0){
			if(!this->table[hash(item)].find(item))
				grow();
                    }else{
                        grow();
                    }
		}

		if(this->table[hash(item)].add(item)){
			this->size++;
		}
		
	}

	void remove(const ItemType& item) {
            if(this->tableSize > 0){
		if(this->table[hash(item)].remove(item)){
                        this->size--;
                }
		if(this->size <= this->tableSize / 2)
			shrink();
            }
	}
	void removeAll(){
		delete[] this->table;
		this->table = new List<ItemType>[1]();
		this->tableSize = 1;
		this->size = 0;
	}

	bool find(const ItemType& item) {
		if(this->tableSize > 0)
			return this->table[hash(item)].find(item);
		return false;
	}

	string print(){
		
		stringstream output;
		if(this->size > 0){
			for(int i = 0; i < this->tableSize; i++){
				List<string>::Node* current = this->table[i].head;
				int count = 1;
				output << "hash " << i << ": ";
				while(current != NULL){

					output << current->item << " ";
					if(count % 8 == 0)
						output << endl << "hash " << i << ": ";
					count++;
					current = current->next;
				}
				output << endl;
			}
		}
		
		return output.str();
	}

};

