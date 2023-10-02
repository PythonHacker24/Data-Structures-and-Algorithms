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
    ListNode* reverseList(ListNode* head) {

        // Handling the edge cases
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        // Setting up the pointers
        ListNode* temp = head;
        ListNode* after = head->next;
        ListNode* before = nullptr;

        // Moving the pointers
        while (after != nullptr){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

        // Moving away the head
        head = before;

        // Returning the head
        return head;
    }
};
