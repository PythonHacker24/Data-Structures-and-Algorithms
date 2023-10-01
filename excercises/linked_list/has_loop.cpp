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
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
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
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        // Solution to the Problem 
        bool hasLoop(){
            Node* fast = head;
            Node* slow = head;
            while(fast != NULL && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast){
                    return true;
                }
            }
            return false;
        }
        
};

/*

Instructor has the same solution as given. This algorithm is called "tortoise and hare" (or "Floyd's cycle-finding") algorithm

*/