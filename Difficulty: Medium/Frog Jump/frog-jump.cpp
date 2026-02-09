class Solution {
  public:
    int f(int ind, vector<int>& height,vector<int>& dp) {
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int jumpOne = f(ind-1, height,dp) + abs(height[ind] - height[ind-1]); 
        int jumpTwo = INT_MAX;
        
        if(ind>1) {
            jumpTwo = f(ind-2, height,dp) + abs(height[ind] - height[ind-2]);
        }
        
        return dp[ind] = min(jumpOne, jumpTwo);
        
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n+1,-1);
        
        return f(n-1,height,dp);
    }
};