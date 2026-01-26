class Solution {
  public:/*
    int f(int ind, int sum, vector<int>& arr, vector<vector<int>>&dp) {
        if(sum==0) return 1;
        if(ind==0) return arr[0] == sum;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notTake = f(ind-1, sum, arr, dp);
        int take = 0;
        if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);
        
        return dp[ind][sum] = take + notTake;
    }*/
    int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> prev(target+1, 0), cur(target+1, 0);

    if (arr[0] == 0) {
        prev[0] = 2;
    } else {
        prev[0] = 1;
        if (arr[0] <= target)
            prev[arr[0]] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= target; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (arr[ind] <= sum)
                take = prev[sum - arr[ind]];

            cur[sum] = (take + notTake) % mod;
        }
        prev = cur;
    }

    return prev[target];
    }

};