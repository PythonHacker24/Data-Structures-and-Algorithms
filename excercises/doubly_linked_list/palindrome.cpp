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

        // This is the Solution
        bool isPalindrome(){
            if (length == 0) return false;
            if (length == 1) return true;
            Node* begin = head;
            Node* end = tail;
            int temp;
            int itterate = 0;
            if (length % 2 == 0){
                itterate = length / 2;
            }
            if (length % 2 != 1){
                int k = length - 1;
                itterate = k / 2;
            }
            for (int i = 0; i <= itterate; i++){
                if (begin->value != end->value) return false;
                begin = begin->prev;
                end = end->next;
            }
            return true;
        }

};

/*
Tutor's Solution

bool isPalindrome() {
    // Return true if list has 0 or 1 element
    if (length <= 1) return true;
 
    // Initialize forwardNode pointer to head node
    Node* forwardNode = head;
 
    // Initialize backwardNode pointer to tail node
    Node* backwardNode = tail;
 
    // Iterate through half of the list
    for (int i = 0; i < length / 2; i++) {
        // Check if forwardNode and backwardNode values match
        if (forwardNode->value != backwardNode->value) return false;
 
        // Move forwardNode pointer to the next node
        forwardNode = forwardNode->next;
 
        // Move backwardNode pointer to the previous node
        backwardNode = backwardNode->prev;
    }
 
    // If all pairs of values matched, return true
    return true;
}
*/