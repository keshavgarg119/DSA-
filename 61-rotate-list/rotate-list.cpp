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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==nullptr || head->next==nullptr || k==0) return head;

        ListNode* temp = head;
        int length = 1;
        while(temp->next != nullptr) {
            length++;
            temp = temp->next;
        }

        k %= length; // where n is the length of the linked list

        temp->next = head;  // makin the linked list circular
        int stepsToNewTail = length-k;
        ListNode* NewTail = head;
        for(int i=1; i<stepsToNewTail; i++) {
            NewTail = NewTail->next;      // move to the newTail from the head
        }

        ListNode* newHead = NewTail->next;
        NewTail->next = nullptr;

        return newHead;


    }
};