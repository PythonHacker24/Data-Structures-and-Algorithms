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

        bool search(char key){
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

        int key_count(){
            int count = 0;
            for (int i = 0; i < SIZE; i++){
                Node* temp = dataMap[i];
                while (temp != nullptr){
                    if (temp->value) count++;
                    temp = temp->next;
                }
            }
            return count;
        }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        HashTable* newHashTable = new HashTable();
        for (int i = 0; i < s.length(); i++){
            newHashTable->set(s[i], true);
        }

        for (int i = 0; i < t.length(); i++){
            if(newHashTable->search(t[i]) == false) return false;  
        }
        if (newHashTable->key_count() != 0) return false;
        return true;
    }
};
