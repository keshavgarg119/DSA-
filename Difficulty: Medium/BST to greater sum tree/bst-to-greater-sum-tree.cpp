/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    
    int sum = 0;
    void transformTree(Node *root) {
        // code here
        
        if(root == nullptr) return;
        transformTree(root->right);
        
        int temp =  root->data;
        root->data = sum;
        sum += temp;;
        
        transformTree(root->left);
        
    }
};