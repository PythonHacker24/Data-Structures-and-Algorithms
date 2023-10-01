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

#include <iomanip>
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
    int countNodes(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return count;

        Queue* myQueue = new Queue();
        count = count + myQueue->add(root);

        while(myQueue->length != 0){
            TreeNode* temp = myQueue->pop();
            if (temp->left != nullptr){
                count = count + myQueue->add(temp->left);
            }
            if (temp->right != nullptr){
                count = count + myQueue->add(temp->right);
            }
        }
        return count;
    }
};
