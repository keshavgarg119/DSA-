class Solution {
  public:
  
    void findSums(int index, int sum, vector<int>&arr, vector<int>&subsetSum) {
        if(index == arr.size()) {
            subsetSum.push_back(sum);
            return;
        }
        
        findSums(index+1, sum+arr[index], arr, subsetSum);
        findSums(index+1, sum, arr, subsetSum);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>subsetSum;
        findSums(0,0,arr,subsetSum);
        sort(subsetSum.begin(),subsetSum.end());
        return subsetSum;
        
    }
};