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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;  
        ListNode* temp = head;
        ListNode* after = head->next;
        
        while (after != nullptr){
            if (after->val == temp->val){
                temp->next = after->next;
                delete after;
                after = temp->next;
            }
            else{
                after = after->next;
                temp = temp->next;
            }
        }
        return head;
    }
};
