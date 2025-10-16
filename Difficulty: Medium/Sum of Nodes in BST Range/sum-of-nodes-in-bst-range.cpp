/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(root == nullptr) return 0;
        
        int sum = 0;
        if(root->data <= r && root->data >= l) {
            sum += root->data;
            sum += nodeSum(root->left,l,r);
            sum += nodeSum(root->right,l,r);
        }
        
        else if(root->data < l) {
            sum += nodeSum(root->right,l,r);
        }
        else {
            sum += nodeSum(root->left,l,r);
        }
        return sum;
    }
};
