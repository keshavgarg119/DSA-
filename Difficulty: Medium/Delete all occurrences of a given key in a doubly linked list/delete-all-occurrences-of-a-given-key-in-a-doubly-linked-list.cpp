// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
       Node* temp = *head_ref;
       
       while(temp!=nullptr) {
           if(temp->data==x) {
               
               if(temp == *head_ref) {
                   *head_ref = temp->next;
                }
                
               Node* nextnode = temp->next;
               Node* prevnode = temp->prev;
               
               if(nextnode!=nullptr) {
                   nextnode->prev = prevnode;
               }
               
               if(prevnode!=nullptr) {
                   prevnode->next = nextnode;
               }
               
               delete temp;
               temp = nextnode;
           }
           else {
               temp = temp->next;
           }
       }
    }
};