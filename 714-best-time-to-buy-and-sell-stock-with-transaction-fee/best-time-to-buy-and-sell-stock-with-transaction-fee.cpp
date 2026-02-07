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
        //vector<int>cur(2,0), next(2,0);

        int aheadBuy, aheadNotBuy, curBuy, curNotBuy;
        aheadBuy = aheadNotBuy = 0;

        for(int ind=n-1; ind>=0; ind--) {
            curNotBuy = max(prices[ind] - fee + aheadBuy, 0 + aheadNotBuy);    
                    
            curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);
         
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return curBuy;
    }
};