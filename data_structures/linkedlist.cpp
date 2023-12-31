#include <iostream>

using namespace std;

/*
Notes:
-> is used to access the public members of a class, structure, 
or members of union with the help of a pointer variable.
*/

// Program for creating a Linked List in C++

// This class will create a Node
class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

// This will be the class that will create a Linked List
class LinkedList{
    private:
        Node* head;          // Create a pointer called head which will point to the start of the Linked List
        Node* tail;          // Create a pointer called tail which will point to the end of the Linked List
        int length;          // Variable which will hold the length of the Linked List

    public:
        LinkedList(int value){
            Node* newNode = new Node(value);     // newNode will be the pointer that will create a new node
            head = newNode;                      // head will be a pointer pointing to the new node
            tail = newNode;                      // tail will be a pointer pointing to the new node
            length = 1;                          // length of this new node will be equal to 1
        }

        // LinkedList* myLinkedList = new LinkedList(4);

        // Constructer development ends here 

        void PrintList(){
            Node* temp = head;                  // temp pointer will hold the value of the head pointer. This is where the start of the Linked List exists.
            while (temp != nullptr){            // While temp is not equal to the null pointer which means it is not the end of the list, do the following.
                cout << temp->value << endl;    // Here, the temp will contain the value of the current Node
                // Here, temp is accessing the value from Node class
                temp = temp->next;              // Here, the temp pointer gets the address of the next node from the next pointer. This is how the next node will be used.
                // Here, temp is accessing the value next variable from the Node class
            }

            // This while loop will be executed untill the last node is reached, in which case, the temp pointer will be a null pointer (as per the defination of the Linked List)
        }

        // Here, references are given to the Node*, in which the value is been calledc
        void getHead(){
            cout << "Head: " << head->value << endl;     // Get the value of the Node to which the head is pointing 
        }

        void getTail(){
            cout << "Tail: " << tail->value << endl;     // Get the value of the Node to which the tail is pointing 
        }

        void getLength(){
            cout << "Length: " << length << endl;        // Get the length of the Linked List
        }

        // This is the destructor that will delete all the values stored in the memory by the Node class
        ~LinkedList(){
            Node* temp = head;
            while (temp){
                head = temp->head;
                delete temp;
                temp = head;
            }            
        }

        // Append function will append a value at the end of the Linked List
        void append(int value){
            Node* myNode = new Node(value);
            if (length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        // Prepend function will add a Node at the start of the Linked List
        void prepend(int value){
            Node* myNode = new Node(value);
            if (length == 0){
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        // Delete function will delete a Node from the Linked List
        void deleteFirst(){
            // Incase the Linked List is empty
            if (length == 0) return;
            Node* temp = head;
            // Incase there is only one Node in the Linked List
            if (length == 1){
                head = nullptr;
                tail = nullptr;
            }
            // Incase there are multiple Nodes in the Linked List
            else{
                head = head->next;
            }
            delete temp;
            length --;
        }

        // deleteLast function will delete the last Node of the Linked List
        void deleteLast(){
            if (length == 0) return;

            // Defining temp and pre pointers 
            Node* temp = head;

            // If the length of the Linked List become 1, point the head and tail pointer to null pointer
            if (length == 0){
                head = nullptr;
                tail = nullptr;
            }

            else{
                Node* pre = head;

                // While loop will continue till temp reaches the last node. When it will, temp will point to the address of the last Node and pre will point to the second last Node
                while (temp->next != nullptr){
                    pre = temp;
                    temp = temp->next;
                }

                // Pointing the tail to the second last Node
                tail = pre;
                tail->next = nullptr;
            }

            // Deleting the Node (initially, it was the last Node) to which the temp pointer was pointing
            delete temp;
            length --;
        }   

        // Get function will return the value of the Node with it's Index
        Node* get(int index){
            // If the given index is less than 0 or greater than the length of the Node, return a null pointer
            if (index < 0 || index >= length){
                return nullptr;
            }

            // If the index is valid, navigate to that node and return it's value
            Node* temp = head;
            for (int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp;
        }

        // Set function will edit the value of the Node of given index. It will be the bool and will return true if the value is modified and false if not set
        bool set(int index, int value){
            Node* temp = get(index)
            if (temp){
                temp->value = value;
                return true;
            }
            return false;
        }

        // Insert function will insert a Node into the Linked List
        bool insert(int index, int value){
            if (index < 0 || index >= length) return false;
            if (index == 0){
                prepend(value);
                return true;
            }
            if (index == length){
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        } 

        // deleteNode function will delete the node of given index
        void deleteNode(int index){
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst;
            if (index == length - 1) return deleteLast;

            Node* prev = get(index - 1);

            // get is not being used for the temp pointer as it has an Operation Complexity of O(n)
            Node* temp = prev->next;

            prev->next = temp->next;
            delete temp;
            length--;
        }

        // reverse function will reverse the orientation of the linked list

        void reverse(){
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* after = temp->next;
            Node* before = nullptr;
            for (i = 0; i < length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }
        }

};

int main(){

    LinkedList* myLinkedList = new LinkedList(4);  // Point the pointer to the LinkedList class which will create a node with the value passed in the ()

    myLinkedList->append(2)

    myLinkedList->getHead();                       // Call the getHead() function from the myLinkedList class
    myLinkedList->getTail();                       // Call the getTail() function from the myLinkedList class
    myLinkedList->getLength();                     // Call the getLength() function from the myLinkedList class

    myLinkedList->append(2)
    myLinkedList->PrintList();                     // Call the PrintList() function from the myLinkedList class

}
