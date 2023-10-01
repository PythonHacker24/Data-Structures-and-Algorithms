#include <iostream>
#include <queue>

using namespace std;

class Node{
	public:
		int value;
		Node* right;
		Node* left;

		Node(int value){
			this->value = value;
			right = nullptr;
			left = nullptr;
		}
};

class BinarySearchTree{
	public:
		Node* root;

	public:
		BinarySearchTree(){
			root = nullptr;
		}

		bool insert(int value){
			Node* newNode = new Node(value);
			if (root == nullptr){
				root = newNode;
				return true;
			}
			Node* temp = root;
			while (true){
				if (newNode->value == temp->value) return false;
				if (newNode->value < temp->value){
					if (temp->left == nullptr){
						temp->left = newNode;
						return true;
					}
					temp = temp->left;
				}
				else{
					if (temp->right == nullptr){
						temp->right = newNode;
						return true;
					}
					temp = temp->right;
				}
			}
		}

		bool contains(int value){
			Node* temp = root;
			while (temp){
				if (value < temp->value){
					temp = temp->left;
				}
				else if (value > temp->value){
					temp = temp->right;
				}
				else{
					return true;
				}
			}
			return false;
		}

		void DFSpostOrder(Node* currentNode){
			if (currentNode->left){
				DFSpostOrder(currentNode->left);
			}
			if (currentNode->right){
				DFSpostOrder(currentNode->right);
			}
			cout << currentNode->value << " ";
		}	

		// Function overloading 
		void DFSpostOrder() {
			DFSpostOrder(root);
		}	
};

int main(){
    BinarySearchTree* myBST = new BinarySearchTree;
    
    myBST->insert(12);
    myBST->insert(4);
    myBST->insert(23);
    myBST->insert(45);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(44);
    myBST->insert(54);
    
    myBST->DFSpostOrder();
}
