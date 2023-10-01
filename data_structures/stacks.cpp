#include <iostream>
#include <climits>

using namespace std;

// Stack have Operational Complexity of 1 as they use prepend and deleteFirst in the Linked List

// Node class will create Nodes that will be pushed into the stack
class Node{
	public:
		int value;
		Node* next;
		Node(int value){
			this->value = value;
			next = nullptr;
		}
};

// Stack class will create stack
class Stack{
	private:
		Node* top;
		int height;

	public:
		// constructor for the stack class
		Stack(int value){
			Node* newNode = new Node(value);
			top = newNode;
			height = 1;
		}

		// printStack function will print the stack contents
		void printStack(){
			Node* temp = top;
			while (temp){
				cout << temp->value << endl;
				temp = temp->next;
			}
		}

		// getTop function will print the value of the Node at the top of the stack
		void getTop(){
			cout << "Top: " << top->value << endl;
		}

		// getHeight function will return the height of the stack
		void getHeight(){
			cout << "Height: " << height << endl;
		}

		// push function pushes the Node at the top of the stack. The prepend function from Linked List can be used where if (length == 0) is checked. Here, we don't need that as there is no tail in the stack.
		void push(int value){
			Node* newNode = new Node(value);
			newNode->next = top;
			top = newNode;
			height++;
		}

		// pop function will pop a Node from top of the stack and will return the Value of the popped node. 
		int pop(){
			if (height == 0) return INT_MIN;     

			/* 
			INT_MIN is the minimum value that C++ can through. 
			This is due to the function being of the type int. 
			An integer has to be returned. 
			Return -1 can misguide about getting -1 because of length equal to 0 or -1 being thee value of the Node that has being popped out. 
			*/

			Node* temp = top;
			int poppedValue = top->value;
			top = top->next;
			delete temp;
			height--;

			return poppedValue;
		}
};

// info function will print information about the stack
void info(Stack* myStack){
	cout << "--------------------" << endl << "Printing Stack Information" << endl;
	cout << "Stack Contents: " << endl; 
	myStack->printStack();
	myStack->getTop();
	myStack->getHeight();
	cout << "--------------------" << endl;
}

int main(){
	Stack* myStack = new Stack(4);
	info(myStack);
    
	myStack->push(7);
	myStack->push(2);
	myStack->push(3);
	myStack->push(1);
	myStack->push(8);
	info(myStack);
	
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;
	cout << myStack->pop() << endl;
	info(myStack);
}