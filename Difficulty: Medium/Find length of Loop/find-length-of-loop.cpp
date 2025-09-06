/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        int length = 1;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast) {
                Node* temp = slow;
                while(temp->next!=slow) {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }
        return 0;
    }
};