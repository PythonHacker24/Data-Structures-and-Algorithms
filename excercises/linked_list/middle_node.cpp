#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
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

        int getHead() {
            if (head == nullptr) {
                return -1;
            } else {
                return head->value;
            }
        }

        int getTail() {
            if (tail == nullptr) {
                return -1;
            } else { 
                return tail->value;
            }  
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        // Solution Section

        Node* findMiddleNode(){
            Node* temp = head;
            int length = 1;
            int index = 0;
            while (temp->next != nullptr){
                temp = temp->next;
                length++;
            }
            if (length % 2 == 0){
                // even length
                index = length / 2;
            }
            if (length % 2 != 0){
                // odd length
                index = (length - 1) / 2;
            }
            temp = head;
            for (int i = 0; i != index; i++){
                temp = temp->next;
            }
            return temp;
            
        }

};

/*

Tutor's Solution (This is called the Tortoise and Hare Algorithm)

//// Floyd's cycle-finding algorithm -> Tortoise and Hare Algorithm ////

Node* findMiddleNode() {
    // Initialize slow and fast pointers to head
    Node* slow = head;
    Node* fast = head;
 
    // Traverse the list until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow pointer one step forward
        slow = slow->next;
        
        // Move fast pointer two steps forward
        fast = fast->next->next;
    }
    
    // When the loop ends, slow points to the middle
    return slow;
}

*/


