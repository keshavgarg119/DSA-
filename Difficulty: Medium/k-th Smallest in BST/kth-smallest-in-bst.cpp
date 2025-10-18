/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count = 0;
    int result = -1;
    void inorder(Node* root, int k) {
        
        if(!root || result!=-1) return;
        
        inorder(root->left, k);
        
        count++;
        if(count==k) {
            result = root->data;
            return;
        }
        
        inorder(root->right, k);
        
    }
    
    int kthSmallest(Node *root, int k) {
        // code here
        
        inorder(root, k);
        
        return result;
        
    }
};