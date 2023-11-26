#include <iostream>

using namespace std;

// Node Class will create a Node
class Node{
	public:
		int value;
		Node* next;

		Node(int value){
			this->value = value;
			next = nullptr;
		}

};

// Queue Class will develop the Queue
class Queue{
	private:
		Node* first;
		Node* last;
		int length;

	public:
		// Constructor for the Queue Class
		Queue(int value){
			Node* newNode = new Node(value);
			first = newNode;
			last = newNode;
			length = 1;
		}

		// printQueue will print the values in the Queue
		void printQueue(){
			Node* temp = first;
			while(temp){
				cout << temp->value << endl;
				temp = temp->next;
			}
		}

		// getFirst will print the value of the first element in the Queue
		void getFirst(){
			cout << "First: " << first->value << endl;
		}

		// getLast will print the value of the last element in the Queue
		void getLast(){
			cout << "Last: " << last->value << endl;
		}

		// getLength will print the length of the Queue
		void getLength(){
			cout << "Length: " << length << endl;
		}

		// enqueue will add a element to the Queue
		void enqueue(int value){
			Node* newNode = new Node(value);
			if (length == 0){
				first = newNode;
				last = newNode;
			}
			else{
				last->next = newNode;
				last = newNode;
			}
			length++;
		}

		// dequeue will remove a element from the Queue
		int dequeue(){
			if (length == 0) return INT_MIN;
			Node* temp = first;
			int dequeuedValue = first->value;
			if (length == 1){
				first = nullptr;
				last = nullptr;
			}
			else{
				first = first->next;
			}
			delete temp;
			length--;
			return dequeuedValue;
		}
};

// info function will return information about the given Queue
void info(Queue* myQueue){
	cout << "----------------" << endl << "Printing the Queue" << endl;
	myQueue->printQueue();
	myQueue->getFirst();
	myQueue->getLast();
	myQueue->getLength();
	cout << "----------------" << endl;
}

int main(){
	Queue* myQueue = new Queue(4);
	info(myQueue);

	myQueue->enqueue(2);
	myQueue->enqueue(8);
	myQueue->enqueue(4);
	myQueue->enqueue(5);

	info(myQueue);
}
