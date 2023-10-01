#include <iostream>
#include <vector>

using namespace std;

// Node Class will create a Node with key-value pair and pointer name next
class Node{
	public:
		string key;
		int value;
		Node* next;

		Node(string key, int value){
			this->key = key;
			this->value = value;
			next = nullptr;
		}
};

// HashTable Class will develop Hash Tables
class HashTable{
	private:
		static const int SIZE = 7;				// SIZE Stores the size of the Hash Table. It is good to create a Hash Table of size of a prime number as it makes the distribution more random.
		Node* dataMap[SIZE];					// dataMap will be a vector of pointers with size of SIZE constant.

	public:
		// The printTable will print the contents in the Hash Table.
		// Logic: For all the locations in the the Hash Table, if any element exists (the element will be a Linked List), go through the key-value pairs in the Linked List.
		void printTable(){
			for(int i = 0; i < SIZE; i++){
				cout << i << ":" << endl;
				if (dataMap[i]){
					Node* temp = dataMap[i];
					while (temp){
						cout << " {" << temp->key << ", " << temp->value << "}" << endl;
						temp = temp->next;
					}
				}
			}
		}

		// The hash function will return the value of hash as per the given input key string
		int hash(string key){
			int hash = 0;
			for (int i = 0; i < key.length(); i++){
				int asciiValue = int(key[i]);				// Here, the string is disected into characters and further converted into integer. There integers will be the ASCII value of the character.
				hash = (hash + asciiValue * 23) % SIZE;		// This is random. Multiplication with prime numbers makes it more random. % will return the remainder when divided with SIZE. If SIZE = 7, remainder must be in the range of (0, 6) which is in scope of Hash Table.
			}
			return hash;
		}

		// The set function will add key-value pair data to the Hash Function
		void set(string key, int value){
			int index = hash(key);
			Node* newNode = new Node(key, value);
			if (dataMap[index] == nullptr){
				dataMap[index] = newNode;
			}
			else{
				Node* temp = dataMap[index];
				while (temp->next != nullptr){
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}

		// The get function searches for the existence of the key-value pair of the given key in the Hash Table
		int get(string key){
			int index = hash(key);
			Node* temp = dataMap[index];
			while (temp != nullptr){
				if (temp->key == key) return temp->value;
				temp = temp->next;
			}
			return 0;
		}

		// The keys function will return a vector containing all the keys from the Hash Table
		vector<string> keys(){
			vector<string> allKeys;
			for (int i = 0; i < SIZE; i++){
				Node* temp = dataMap[i];
				while (temp != nullptr){
					allKeys.push_back(temp->key);
					temp = temp->next;
				}
			}
			return allKeys;
		} 
};

int main(){
	HashTable* myHashTable = new HashTable;
	myHashTable->set("dataset_1", 1000);
	myHashTable->set("dataset_2", 2343);
	myHashTable->set("dataset_3", 1433);
	myHashTable->set("dataset_4", 6564);
	myHashTable->set("dataset_5", 13453);
	myHashTable->set("dataset_6", 35435);
	myHashTable->set("dataset_7", 2434);
	myHashTable->set("dataset_8", 16446);
	myHashTable->set("dataset_9", 23434);
	myHashTable->set("dataset_10", 75675);
	myHashTable->set("dataset_11", 35464);
	myHashTable->set("dataset_12", 546546);
	myHashTable->set("dataset_13", 7565);
	myHashTable->set("dataset_14", 3445);
	myHashTable->set("dataset_15", 5645);
	myHashTable->set("dataset_16", 4543);
	
	myHashTable->printTable();

	vector<string> myKeys = myHashTable->keys();

	for (auto key : myKeys){
		cout << key << " ";
	}
}



