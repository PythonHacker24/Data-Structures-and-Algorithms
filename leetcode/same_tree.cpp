/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Node {
    public:
        TreeNode* value;
        Node* next;
        Node(TreeNode* value){
            this->value = value;
            next = nullptr;
        }
};

class Queue {
    public:
        int length = 0;
        Node* last;
        Node* first;

        Queue(){
            last = nullptr;
            first = nullptr;
        }

        int add(TreeNode* value){
            Node* newNode = new Node(value);
            if (length == 0){
                last = newNode;
                first = newNode;
                length++;
                return 1;
            }
            newNode->next = first;
            first = newNode;
            length++;
            return 1;
        }

        TreeNode* pop(){
            if (length == 0) return nullptr;
            if (length == 1){
                Node* temp = last;
                first = nullptr;
                last = nullptr;
                length--;
                return temp->value;
            }
            Node* temp = first;
            while (temp->next != last){
                temp = temp->next;
            }

            Node* hold = last;
            last = temp;
            TreeNode* answer = hold->value;
            delete hold;
            last->next = nullptr;
            length--;
            return answer;
        }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;

        vector<int> array1;
        vector<int> array2;

        vector<int> pattern1;
        vector<int> pattern2;

        int count1 = 0;
        int count2 = 0;

        Queue* firstQueue = new Queue();
        Queue* secondQueue = new Queue();

        count1 = count1 + firstQueue->add(p);
        count2 = count2 + secondQueue->add(q);

        while (firstQueue->length != 0){
            TreeNode* temp = firstQueue->pop();
            array1.push_back(temp->val);
            
            int indicator1 = 0;
            int indicator2 = 0;
            if (temp->left != nullptr){
                count1 = count1 + firstQueue->add(temp->left);
                indicator1 = indicator1 + 2;
                pattern1.push_back(2);
            }
            if (temp->right != nullptr){
                count1 = count1 + firstQueue->add(temp->right);
                indicator2 = indicator2 + 1;
                pattern1.push_back(1);
            }
            pattern1.push_back(indicator1 + indicator2);
        }

        while (secondQueue->length != 0){
            TreeNode* temp =secondQueue->pop();
            array2.push_back(temp->val);

            int indicator1 = 0;
            int indicator2 = 0;
            if (temp->left != nullptr){
                count2 = count2 + secondQueue->add(temp->left);
                indicator1 = indicator1 + 2;
                pattern2.push_back(2);
            }
            if (temp->right != nullptr){
                count2 = count2 + secondQueue->add(temp->right);
                indicator2 = indicator2 + 1;
                pattern2.push_back(1);
            }
            pattern2.push_back(indicator1 + indicator2);
        }

        if (count1 != count2) return false;

        for (int i = 0; i < pattern1.size(); i++){
            if (pattern1[i] != pattern2[i]) return false;
        }

        for (int i = 0; i < array1.size(); i++){
            if (array1[i] != array2[i]) return false;
        } 

        return true;

    }
};
