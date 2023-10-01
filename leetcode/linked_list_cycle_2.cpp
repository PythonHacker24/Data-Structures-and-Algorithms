/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return nullptr;
        if (head->next->next == nullptr && head->next->next != head) return nullptr;

        ListNode* hare = head;
        ListNode* tortoise = head;

        while (hare != nullptr && hare->next != nullptr){
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (tortoise == hare){
                tortoise = head;

                while (tortoise != hare){
                    tortoise = tortoise->next;
                    hare = hare->next;
                }
                return hare;
            }
        }
        return nullptr;
    }
};
