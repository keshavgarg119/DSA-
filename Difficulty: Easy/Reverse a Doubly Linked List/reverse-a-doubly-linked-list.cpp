/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if (head == nullptr || head->next == nullptr)
            return head;
        DLLNode* curr = head;
        DLLNode* temp = nullptr;
        
        while(curr!=nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            curr = curr->prev;
        }
        
        if(temp !=nullptr) {
            head = temp -> prev;
        }
        return head;
    }
};