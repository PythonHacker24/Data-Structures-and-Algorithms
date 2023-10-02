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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr && head->val == val){
            delete head;
            return nullptr;
        }
        ListNode* temp = head;
        ListNode* before = nullptr;
        while (temp != nullptr){
            if (temp == head && temp->val == val){
                head = head->next;
                delete temp;
                temp = head;
                continue;
            }
            if (temp->val == val){
                before->next = temp->next;
                delete temp;
                temp = before;
            }
            before = temp;
            temp = temp->next;
        }
        return head;
    }
};
