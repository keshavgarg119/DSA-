/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* temp = head;
        if(head == NULL) {
            return new Node(x);
        }
        while(temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = new Node(x);
        temp->next = newNode;
        return head;
        
    }
};