/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>&arr) {
        
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    int findMedian(Node* root) {
        // Code here
        vector<int>ans;
        inorder(root,ans);
        int n = ans.size();
        
        if(n==0) return 0;
        else if(n%2 == 0) return ans[((n/2-1) + (n)/2)/2];
        else return ans[n/2];
        
    }
};