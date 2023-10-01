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

    int powerCalc(int power){
        if (power == 0) return 1;
        int result = 1;
        for (int i = 0; i < power; i++){
            result = result * 2;
        }
        return result;
    }

    int getDecimalValue(ListNode* head) {
        // Defining edge cases
        if (head == nullptr) return 0;
        if (head->next == nullptr) return head->val;

        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            temp = temp->next;
            length++;
        }

        temp = head;
        int result = 0;
        int calc;
        for (int k = 0; k < length; k++){
            if (temp->val == 0){
                temp = temp->next;
                continue;
            }
            calc = powerCalc(length - 1 - k) * temp->val;
            temp = temp->next;
            result = result + calc;
        }
        return result;
    }
};
