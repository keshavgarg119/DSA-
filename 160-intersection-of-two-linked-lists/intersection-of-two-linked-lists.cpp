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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=tempB) {
            /*if(tempA == nullptr) {
                tempA = headB
            } else {
                tempA = tempA->next;
            }*/
            tempA = (tempA==nullptr) ? headB : tempA->next;
            tempB = (tempB==nullptr) ? headA : tempB->next;
        }

        return tempA;

    }
};