/*
// Tree Node
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
  
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void addLeft(Node* curr, vector<int>&res) {
        curr = curr->left;
        
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
        
    }
    
    void addRight(Node* curr,  vector<int>&res) {
        curr = curr->right;
        vector<int>temp;
        
        while(curr) {
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i = temp.size()-1; i>=0; i--) {
            res.push_back(temp[i]); // fill the right boudary elements in the reverse order
        }
        
    }
    
    void addLeaves(Node* root, vector<int>&res) {
        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);
        
        return res;
    }
};