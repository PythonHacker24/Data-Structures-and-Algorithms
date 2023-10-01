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
        void reverse(){
            if (length == 0 || length == 1) return;
            Node* end = tail;
            Node* begin = head;
            int temp;
            int itterate;
            if (length % 2 == 0){
                itterate = (length / 2);
            }
            if (length % 2 != 0){
                int k = length - 1;
                itterate = k / 2;
            }
            for (int i = 0; i < itterate; i++){
                    temp = end->value;
                    end->value = begin->value;
                    begin->value = temp;
                    end = end->prev;
                    begin = begin->next;
            }
        }

};

/*
Tutor's solution

void reverse() {
    // Initialize current pointer to head node
    Node* current = head;
 
    // Initialize temp pointer to nullptr
    Node* temp = nullptr;
 
    // Iterate through the list
    while (current != nullptr) {
        // Save the previous node pointer in temp
        temp = current->prev;
 
        // Swap the previous and next pointers of the current node
        current->prev = current->next;
        current->next = temp;
 
        // Move current pointer to the next node in reversed order
        current = current->prev;
    }
 
    // Swap head and tail pointers
    temp = head;
    head = tail;
    tail = temp;
}

*/