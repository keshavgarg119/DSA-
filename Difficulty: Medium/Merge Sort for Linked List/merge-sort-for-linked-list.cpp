/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  
    Node* sortedMerge(Node* a, Node* b) {
        if(!a) return b;
        if(!b) return a;
        
        Node* result = nullptr;
        
        if(a->data <= b->data) {
            result = a;
            result->next = sortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = sortedMerge(a, b->next);
        }
        return result;
    }
    
    Node* getMiddle(Node* head) {
        if(!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* mergeSort(Node* head) {
        // code here
        if(!head || !head->next) return head;
        
        Node* middle = getMiddle(head);
        Node* nextOfMiddle = middle->next;
        middle->next = nullptr;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextOfMiddle);
        
        return sortedMerge(left, right);
    }
};