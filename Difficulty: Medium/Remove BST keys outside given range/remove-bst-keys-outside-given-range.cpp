/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root == nullptr) {
            return root;
        }
        
        root->left = removekeys(root->left,l,r);
        root->right = removekeys(root->right,l,r);
        
        if(root->data > r) {
            Node* leftNode = root->left;
            delete root;
            return leftNode;
        }
        
        if(root->data < l) {
            Node*  rightNode = root->right;
            delete root;
            return rightNode;
        }
        
        return root;
    }
};