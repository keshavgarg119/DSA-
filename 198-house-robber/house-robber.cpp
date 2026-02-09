class Solution {
public:
    /*int f(int ind, vector<int> &nums, vector<int>& dp) {
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];

        int take = nums[ind] + f(ind-2, nums, dp);
        int notTake = f(ind-1, nums, dp);

        return dp[ind] = max(take, notTake);
        
    }*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int ind=2; ind<n; ind++) {
            int take = nums[ind] + dp[ind-2];
            int notTake = dp[ind-1];

            dp[ind] = max(take, notTake);
        }

        return dp[n-1];
    }
};