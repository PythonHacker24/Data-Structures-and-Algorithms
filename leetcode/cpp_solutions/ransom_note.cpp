// Defining the Node Class
class Node {
    public:
        char key;
        bool value;
        Node* next;
        Node(char key, bool value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

// Defining the HashTable Class
class HashTable {
    private:
        static const int SIZE = 25;
        Node* dataMap[SIZE];

    public:
        int hash(char key){
            int hash = 0;
            int asciiValue = int(key);
            hash = (hash + asciiValue * 23) % SIZE;
            return hash;
        }

        void set(char key, bool value){
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr){
                dataMap[index] = newNode;
            }
            else{
                Node* temp = dataMap[index];
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        bool get(char key){
            int index = hash(key);
            Node* temp = dataMap[index];
            if (temp == nullptr) return false;
            if (temp->key == key && temp->next == nullptr){
                dataMap[index] = nullptr;
                return true;
            }
            Node* front = temp->next;
            while (front != nullptr){
                if (front->key == key){
                    temp->next = front->next;
                    delete front;
                    return true;
                }
                front = front->next;
                temp = temp->next;
            }
            return false;
        }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        HashTable* myHashTable = new HashTable();

        // Filling the HashTable with the values of magazine
        for (int i = 0; i < magazine.length(); i++){
            myHashTable->set(magazine[i], true);
        }

        // Validiting the existence of all ransomNote characters in the HashTable
        for (int i = 0; i < ransomNote.length(); i++){
            if (myHashTable->get(ransomNote[i]) == false) return false;
        }
        return true;
    }
};
