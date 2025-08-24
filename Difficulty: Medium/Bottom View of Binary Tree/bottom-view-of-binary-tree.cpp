/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(!root) return ans;
        
        map<int,int>mp;  // we store {hd, node->val}
        queue<pair<Node*,int>>q; // we store {node,hd}
        q.push({root,0});
        
        while(!q.empty()) {
            
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int hd = p.second;
            
            mp[hd] = node->data;
            
            if(node->left) q.push({node->left, hd-1});
            if(node->right) q.push({node->right, hd+1});
            
        }
        
        for(auto it:mp) {
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};