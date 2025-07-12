/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    
    int helper(Node* temp) {
        if (temp == nullptr) return 1;

        int carry = helper(temp->next);
        int sum = temp->data + carry;
        temp->data = sum % 10;
        return sum / 10;
    }

    Node* addOne(Node* head) {
        int carry = helper(head);

        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
