/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>path;
        vector<vector<int>>result;
        dfs(root,path,result);
        return result;
    }
    
    void dfs(Node* root, vector<int>&path, vector<vector<int>>&result) {
        
        if(!root) return;
        
        path.push_back(root->data);
        
        if(!root->left  && !root->right) {
            result.push_back(path);
        }
        dfs(root->left, path, result);
        dfs(root->right, path, result);
        
        path.pop_back();
    }
};