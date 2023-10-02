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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* before = head;
        int length = 0;

        // Handling length == 1
        if (head->next == nullptr){
            delete head;
            return nullptr;
        }

        // Calculating the length of the Linked List
        while (temp != nullptr){
            length++;
            temp = temp->next;
        }

        // Handling edge cases
        if (n == length){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        for (int i = 0; i < length - n - 1; i++){
            before = before->next;
        }

        temp = before->next;
        before->next = temp->next;
        delete temp;
        return head;
    }
};
