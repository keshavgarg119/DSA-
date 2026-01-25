class Solution {
  public:
    /*bool f(int ind, int target, vector<int>& arr) {
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        return dp[ind][target] = take | notTake;
    }*/
    bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    // Base case: sum = 0 is always possible
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // First element initialization
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= sum; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = take || notTake;
        }
    }

    return dp[n - 1][sum];
    }

};