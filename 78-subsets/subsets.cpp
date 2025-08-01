class Solution {
public:
    
    void printSubsets(int index, vector<int>& arr, vector<vector<int>> &result, vector<int> &current) {

        // base case
        if(index==arr.size()) {
            result.push_back(current);
            return;
        }

        // recursive calls
        // including the element
        current.push_back(arr[index]);
        printSubsets(index+1, arr, result, current);

        // removing the element
        current.pop_back();
        printSubsets(index+1, arr, result, current);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> current;
        printSubsets(0,nums,result,current);
        return result;

    }
};