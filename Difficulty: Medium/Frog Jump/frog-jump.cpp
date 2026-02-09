class Solution {
  public:
    /*int f(int ind, vector<int>& height,vector<int>& dp) {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int jumpOne = f(ind-1, height,dp) + abs(height[ind] - height[ind-1]); 
        int jumpTwo = INT_MAX;
        
        if(ind>1) {
            jumpTwo = f(ind-2, height,dp) + abs(height[ind] - height[ind-2]);
        }
        
        return dp[ind] = min(jumpOne, jumpTwo);
        
    }*/
    // using tabulation
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        //vector<int>dp(n,0);
        int prev1 = 0;
        int prev2 = 0;
        
        for(int ind=1; ind<n; ind++) {
            int jumpOne = prev1 + abs(height[ind] - height[ind-1]); 
            int jumpTwo = INT_MAX;
            
            if(ind>1) {
                jumpTwo = prev2 + abs(height[ind] - height[ind-2]);
            }
            
            int cur = min(jumpOne, jumpTwo);
            
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
};