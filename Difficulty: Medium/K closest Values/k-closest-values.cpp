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
  
    void inorder(Node* root, vector<int>&arr) {
        if(!root) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        if(!root) return {};
        vector<int> arr;
        inorder(root, arr);
        
        int low = 0;
        int n = arr.size();
        int high = n-1;
        
        // binary search on sorted array
        while(low < high) {
            int mid = low+(high-low)/2;
            if(arr[mid]<target){
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        
        int left = low-1;
        int right = low;
        vector<int>result;
        
        while(k-- >0) {
            if(left<0) result.push_back(arr[right++]);
            else if(right>=n) result.push_back(arr[left--]);
            else {
                
                int diffLeft = abs(arr[left]-target);
                int diffRight = abs(arr[right]-target);
                
                if(diffLeft <= diffRight) {
                    result.push_back(arr[left--]);
                }
                else {
                    result.push_back(arr[right++]);
                }
            }
        }
        return result;
    }
};