#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail;
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        
        // This was my solution
        void swapFirstLast(){
            if (length == 0 || length == 1) return;
            int temp = head -> value;
            head -> value = tail -> value;
            tail -> value = temp;
        }

};

/*
Tutor's solution

void swapFirstLast() {
    // Check if the list has less than 2 nodes
    if (length < 2) return;
 
    // Store head node's value in a temp variable
    int temp = head->value;
 
    // Set head node's value to tail node's value
    head->value = tail->value;
 
    // Set tail node's value to the original head node's value
    tail->value = temp;
}

*/