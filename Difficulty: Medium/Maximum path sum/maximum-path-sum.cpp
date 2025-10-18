/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int findMaxUtil(Node* root, int &res) {
        if(root == nullptr) return 0;
        
        int l = findMaxUtil(root->left, res);
        int r = findMaxUtil(root->right, res);
        
        int maxSingle = max(max(l,r)+root->data, root->data);
        int maxBoth = max(maxSingle, l+r+root->data);
        
        res = max(res, maxBoth);
        
        return maxSingle;
    }
    
    int findMaxSum(Node *root) {
        // code here
        int res = INT_MIN;
        findMaxUtil(root, res);
        return res;
    }
};