#include <iostream>

using namespace std;

// Creating the Node Class
class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

// Creating Double Linked List Class
class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  // Constructor for the Doubly Linked List
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  // Destructor for the Doubly Linked List
  ~DoublyLinkedList() {
    Node* temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  // printList will print the Linked List
  void printList() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }

  void getHead() { cout << "Head: " << head->value << endl; }

  void getTail() { cout << "Tail: " << tail->value << endl; }

  void getLength() { cout << "Length: " << length << endl; }

  // append funtion will append a Node at the end of the Linked List
  void append(int value) {
    Node *newNode = new Node(value);
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

  // deleteLast function will delete the last Node of the Linked List
  void deleteLast(){
    if (length == 0) return;
    Node* temp = tail;
    if (length == 1){
      head = nullptr;
      tail = nullptr;
    }
    else{
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete temp;
    length--;
  }

  // prepend function will prepend a Node at the beginning of the Linked List
  void prepend(int value){
    Node* newNode = new Node(value);
    if (length == 0){
      head = newNode;
      tail = newNode;
    }
    else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length++;
  }

  // deleteFirst function will delete the first Node of the Linked List
  void deleteFirst(){
    if (length == 0) return;
    Node* temp = head;
    if (length == 1){
      head = nullptr;
      tail = nullptr;
    }
    else{
      head = head->next;
      head->prev = nullptr;
    }
    delete temp;
    length--;
  }

  // get function will return the pointer pointing to the given index of the Linked List
  Node* get(int index){
    if (index < 0 || index >= length) return;
    Node* temp = head;
    if (length < length / 2){
      for (int i = 0; i < index; i++){
        temp = temp->next;
      }
    }
    else{
      temp = tail;
      for (int i = length - 1; i > index; i--){
        temp = temp->prev;
      }
    }
    return temp;
  }

  // set function will set the value of the Node of a given index to the  given value
  bool set(int index, int value){
    Node* temp = get(index);
    if (temp != nullptr){
      temp->value = value;
      return true;
    }
    return false;
  }

  // insert function will be used to insert a Node a given value at given index 
  bool insert(int index, int value){
    if (index < 0 || index > length) return false;
    if (index == 0){
      prepend(value);
      return true;
    }
    if (index == length){
      append(value);
      return true;
    }
    Node* newNode = new Node(value);
    Node* before = get(index - 1);
    Node* after = before->next;
    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;
    length++;
    return true;
  }

  // deleteNode function will delete the Node of given index
  void deleteNode(int index){
    if (index < 0 || index >= length) return;
    if (index == 0) return deleteFirst();
    if (index == length - 1) return deleteLast();
    Node* temp = get(index);
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    length--;
  }

};

// Print function will print information about the linked list for debugging purposes. This function has not been defined in the class.
void print(DoublyLinkedList* myDLL){
  cout << "---------------------" << endl;
  cout << "Printing Linked List" << endl;
  myDLL->printList();
  myDLL->getHead();
  myDLL->getTail();
  myDLL->getLength();
  cout << "---------------------" << endl;
}

int main() {
  DoublyLinkedList* myDLL = new DoublyLinkedList(7);
  myDLL->append(3);
  myDLL->append(4);
  myDLL->append(5);
  myDLL->append(1);
  print(myDLL);
  
  cout << "Deleting Last" << endl;
  myDLL->deleteLast();
  print(myDLL);
  
  cout << "Prepending" << endl;
  myDLL->prepend(5);
  print(myDLL);

  cout << "Appending" << endl;
  myDLL->append(8);
  print(myDLL);  

  cout << "Deleting First" << endl;
  myDLL->deleteFirst();
  print(myDLL);

  cout << "Getting the value of given Index" << endl;
  cout << myDLL->get(2)->value << endl;
  print(myDLL);

  cout << "Setting the value of index 2 to 10" << endl;
  myDLL->set(2, 10);
  print(myDLL);

  cout << "Inserting a Node of value 8 at index 3" << endl;
  myDLL->insert(3, 8);
  print(myDLL);
}
