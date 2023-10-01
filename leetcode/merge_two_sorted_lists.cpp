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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr && list2 != nullptr) return list2;
        if (list2 == nullptr && list1 != nullptr) return list1;

        ListNode* pointer = nullptr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // Initial case for pointer setup
        if (temp1->val <= temp2->val){
            pointer = temp1;
            temp1 = temp1->next;;
        }
        else{
            pointer = temp2;
            temp2 = temp2->next;;
        }

        ListNode* result = pointer;

        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1->val <= temp2->val){
                pointer->next = temp1;
                pointer = temp1;
                temp1 = temp1->next;
            }
            else{
                pointer->next = temp2;
                pointer = temp2;
                temp2 = temp2->next;
            }
        }

        if (temp1 != nullptr && temp2 == nullptr){
            pointer->next = temp1;
        }
        if (temp2 != nullptr && temp1 == nullptr){
            pointer->next = temp2;
        }

        return result;
    }
};
