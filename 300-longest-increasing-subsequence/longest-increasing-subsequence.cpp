class Solution {
public:
    int f(int ind, int prev, vector<int>&arr, int n,  vector<vector<int>>&dp) {
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int length = f(ind+1, prev, arr, n,dp);
        if(prev==-1 || arr[ind] > arr[prev]) {
            length = max(length, 1+f(ind+1, ind, arr, n,dp));
        }

        return dp[ind][prev+1] = length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};