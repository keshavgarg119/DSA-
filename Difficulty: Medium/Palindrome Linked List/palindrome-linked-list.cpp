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
    bool isPalindrome(Node *head) {
        if(!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* prev = nullptr;
        Node* curr = slow;
        while(curr){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        Node* first = head;
        Node* second = prev;
        while(second){
            if(first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
