class Solution {
public:
    /*int f(int ind, int k, vector<int> &heights, vector<int> &dp) {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(ind-j >= 0) {
                int jump = f(ind-j, k, heights,dp) + abs(heights[ind] - heights[ind-j]);
                minSteps = min(minSteps, jump);
            }
        }

        return dp[ind] = minSteps;
    }*/
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);

        dp[0] = 0;

        for(int ind = 1; ind < n; ind++) {
            int minSteps = INT_MAX;

            for(int j = 1; j <= k; j++) {
                if(ind - j >= 0) {
                    int jump = dp[ind - j]
                               + abs(heights[ind] - heights[ind - j]);
                    minSteps = min(minSteps, jump);
                }
            }

            dp[ind] = minSteps; 
        }

        return dp[n - 1];
    }
};