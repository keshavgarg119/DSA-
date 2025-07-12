/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head;
        
        while(temp!=nullptr && temp->next!=nullptr) {
            Node* nextNode = temp->next;
            
            while(nextNode!=nullptr && nextNode->data == temp->data) {
                Node* dup = nextNode;
                nextNode = nextNode->next;
                delete dup;
            }
            
            temp->next = nextNode;
            if(nextNode!=nullptr) nextNode->prev = temp;
            temp = nextNode;
        }
        
        return head;
    }
};