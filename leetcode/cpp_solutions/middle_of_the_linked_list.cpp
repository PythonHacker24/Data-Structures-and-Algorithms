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
    ListNode* middleNode(ListNode* head) {
            ListNode* temp = head;
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
