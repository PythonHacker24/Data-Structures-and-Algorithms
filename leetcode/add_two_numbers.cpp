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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* baseNode = new ListNode(0);
        ListNode* temp = baseNode;
        int quotient = 0;
        int remainder = 0;
        while (l1 != nullptr || l2 != nullptr || quotient != 0){
            int sum = 0;

            if (l1 != nullptr){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + quotient;
            remainder = sum % 10;
            ListNode* newNode = new ListNode(remainder);
            temp->next = newNode;
            temp = temp->next;
            quotient = sum / 10;
            
        }
        ListNode* result = baseNode->next;
        delete baseNode;
        return result;
    }
};
