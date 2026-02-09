class Solution {
public:

    void findSubsets(int index, vector<int>&arr, vector<int> &ds, vector<vector<int>> &ans) {
        
        ans.push_back(ds);

        for(int i=index; i<arr.size(); i++) {
            if(i!=index && arr[i]==arr[i-1]) continue; // skipping the duplicates
            ds.push_back(arr[i]);
            findSubsets(i+1,arr,ds,ans);
            ds.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;

    }
};