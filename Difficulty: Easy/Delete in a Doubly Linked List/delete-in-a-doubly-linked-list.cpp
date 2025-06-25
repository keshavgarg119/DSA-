/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            return head;
        }

        Node* curr = head;
        int count = 1;

        while (curr != nullptr && count < x) {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) return head; 

        if (curr->prev != nullptr)
            curr->prev->next = curr->next;
        if (curr->next != nullptr)
            curr->next->prev = curr->prev;

        delete curr;

        return head;
    }
};
