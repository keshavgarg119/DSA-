class Solution {
public:
    /*long f(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>&dp) {
        if(ind == n) return 0;
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy) {
            profit = max(-prices[ind] + f(ind+1, 0, prices, n,dp),
                          0 + f(ind+1, 1, prices, n,dp));
        }
        else {
            profit = max(prices[ind] + f(ind+1, 1, prices, n,dp),
                          0 + f(ind+1, 0, prices, n,dp));
        }

        return dp[ind][buy] = profit;
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2,0));
        vector<int>next(2,0), cur(2,0);
        cur[0] = cur[1] = 0;
        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                int profit = 0; 
                if(buy) {
                    profit = max(-prices[ind] + next[0],
                                0 + next[1]);
                }
                else {
                    profit = max(prices[ind] + next[1],
                                0 + next[0]);
                }
                cur[buy] = profit;
            }
            next = cur;
        }
        return cur[1];
    }
    
};