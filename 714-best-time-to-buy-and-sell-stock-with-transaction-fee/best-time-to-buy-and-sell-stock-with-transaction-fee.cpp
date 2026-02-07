class Solution {
public:
    /*int f(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1) {
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,prices,fee,dp),
                                                 0 + f(ind+1,1,prices,fee,dp));
        }
        else {
            return dp[ind][buy] = max(prices[ind] - fee + f(ind+1,1,prices,fee,dp),
                                                0 + f(ind+1,0,prices,fee,dp));
        }
    }*/
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2,0));
        vector<int>cur(2,0), next(2,0);

        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy==1) {
                    cur[buy] = max(-prices[ind] + next[0],
                                                  0 + next[1]);
                }
                else {
                    cur[buy] = max(prices[ind] - fee + next[1],
                                                       0 + next[0]);
                }
            }
            next = cur;
        }

        return cur[1];
    }
};