/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast = head;
        
        int length = 1;
        while(fast != nullptr  && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast) {
                Node* temp = slow;
                while(temp->next != slow) {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }
        return 0; 
        
    }
};