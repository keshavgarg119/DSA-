/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {

        if(root==nullptr) {
            return 0;
        }

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }

    int getLeftHeight(TreeNode* root) {

        int height = 0;

        while(root) {
            height++;
            root = root->left;
        }
        
        return  height;

    }

    int getRightHeight(TreeNode* root) {

        int height = 0;

        while(root) {
            height++;
            root = root->right;
        }

        return  height;
        
    }
};