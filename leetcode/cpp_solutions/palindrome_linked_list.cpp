/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) return true;
        ListNode* temp = head;
        ListNode* star = head;
        int length = 0;
        while (star != nullptr){
            star = star->next;
            length++;
        }
        int array[length];
        int i = 0;
        // Converting Linked List into Array
        while (temp != nullptr){
            array[i] = temp->val;
            temp = temp->next; 
            i++;
        }

        // Calculating size of the array
        int size = sizeof(array) / sizeof(array[0]);
        if (size % 2 == 0){
            int counter = size / 2;
            for (int i = 0; i < counter; i++){
            if (array[i] != array[size - 1 - i]){
                return false;
            }
        }
        return true;
        }
        else{
            int counter = (size - 1) / 2;
            for (int i = 0; i < counter; i++){
            if (array[i] != array[size - 1 - i]){
                return false;
            }
        }
        return true;
        }
        
        
    }
};
