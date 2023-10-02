// Defining the Node Class
class Node {
    public:
        char key;
        char value;
        Node* next;
        Node(char key, char value){
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

        bool check_key(char key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp != nullptr){
                if (temp->key == key) return true;
                temp = temp->next;
            }
            return false;
        }

        bool check_value(char value){
            for (int i = 0; i < SIZE; i++){
                Node* temp = dataMap[i];
                while (temp != nullptr){
                    if (temp->value == value) return true;
                    temp = temp->next;
                }
            }
            return false;
        }

        void set(char key, char value){
            int index = hash(key);
            if (check_key(key) == true) return;
            if (check_value(value) == true) return;
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

        char get(char key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while(temp != nullptr){
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        HashTable* myHashTable = new HashTable();
        // Loading s into the HashTable

        for (int i = 0; i < s.length(); i++){
            myHashTable->set(s[i], t[i]);
        }

        for (int i = 0; i < s.length(); i++){
            char trigger = myHashTable->get(s[i]);
            if (trigger != t[i]) return false;
        }
        return true;
        
    }
};
