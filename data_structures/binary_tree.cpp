#include <iostream>

using namespace std;

// Node Class will create a Node
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

// BinarySearchTree Class develops a Binary Search Tree
class BinarySearchTree{
	public:
		Node* root;

	public:
		/*
		BinarySearchTree(int value){
			Node* newNode = new Node(value);
			root = newNode;
		}

		In this case, a Node is being created as soon as the BinarySearchTree class is called.
		This can be a approach can also be done differently.
		Rather than creating a new Node, keep the Binary Tree empty.
		Set the root pointer nullptr.
		*/

		// Constructor for BinarySearchTree Class
		BinarySearchTree(){
			root = nullptr;
		}

		// The insert function will insert a Node of given value to the Binary Search Tree
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

		// The contains function will search the given value in the Binary Search Tree and return true if the value is present in the Tree or false if the value is not present in the Binary Search Tree
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
    
    cout << myBST->root->right->left->value << endl;
}

/*

My solution to the contains() function

bool contains(int value){
            if (root == nullptr) return false;
            Node* temp = root;
            int mark = 0;
            while (mark == 0){
                if (value == temp->value){
                    mark = 0;
                    return true;
                }
                if (value < temp->value){
                    if (temp->left == nullptr){
                        mark = 1;
                        return false;
                    }
                    temp = temp->left;
                }
                if (value > temp->value){
                    if (temp->right == nullptr){
                        mark = 1;
                        return false;
                    }
                    temp = temp->right;
                }
            }
        }

*/
