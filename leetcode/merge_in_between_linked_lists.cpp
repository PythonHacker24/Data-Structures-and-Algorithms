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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* before = list1;
        ListNode* after = list1;
        ListNode* pointer = list2;
        ListNode* temp;

        if (a == 1){
            before = list1;
        }
        else{
            for (int i = 0; i < a - 1; i++){
                before = before->next;
            }
        }
        for (int k = 0; k < b; k++){
            after = after->next;
        }

        if (a == b){
            before->next = list2;
            while (pointer->next != nullptr){
                pointer = pointer->next;
            }
            pointer->next = after->next;
            delete after;
            return list1;
        }

        temp = before->next;
        before->next = list2;
        if (temp != after){
            delete temp;
        }

        temp = after->next;
        while (pointer->next != nullptr){
            pointer = pointer->next;
        }

        pointer->next = temp;
        delete after;

        return list1;
    }
};
