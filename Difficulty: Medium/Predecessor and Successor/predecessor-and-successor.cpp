/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = nullptr;
        Node* succ = nullptr;
        
        while(root != nullptr) {
            if(root->data == key) {
                if(root->left!=nullptr) {
                    Node* temp = root->left;
                    while(temp->right) {
                        temp = temp->right;
                    }
                    pre = temp;
                }
                
                if(root->right!=nullptr) {
                    Node* temp = root->right;
                    while(temp->left) {
                        temp = temp->left;
                    }
                    succ = temp;
                }
                break;
            }
            else if(key < root->data) {
                succ = root;
                root = root->left;
            }
            else {
                pre = root;
                root = root->right;
            }
        }
        
        return {pre,succ};
    }
};