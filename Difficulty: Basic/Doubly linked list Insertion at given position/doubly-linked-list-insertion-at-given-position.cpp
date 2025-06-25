/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node *curr = head;
        Node* newNode = new Node(data);
        int count = 0;
        
        while(count < pos && curr!=NULL) {
            count++;
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        if(curr->next!=NULL) {
            curr->next->prev =  newNode;
        }
        curr->next = newNode;
        
        return head;
    }
};