class Solution {
public:

    void findCombination(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {

        // base case
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        // checking for all the other combination without duplicates
        for(int i=index; i<arr.size(); i++) {
            
            if(i>index && arr[i] == arr[i-1])  continue;// checking for duplicates
            if(arr[i] > target) break; // checking whether any number less than target still present
            
            ds.push_back(arr[i]);
            findCombination(i+1, target-arr[i], arr, ans, ds);
            ds.pop_back();

        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;

    }
};