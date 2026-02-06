class Solution {
public:
    /*int f(int ind, int tranNo, vector<int>& prices, int n, int k, vector<vector<int>>&dp) {
        if(tranNo == 2*k || ind==n) return 0;
        if(dp[ind][tranNo]!=-1) return dp[ind][tranNo];

        if(tranNo%2==0) {
            return dp[ind][tranNo] = max(-prices[ind] + f(ind+1, tranNo+1, prices, n,k,dp),
                                                    0 + f(ind+1, tranNo, prices, n,k,dp));
        }
        else {
            return dp[ind][tranNo] = max(prices[ind] + f(ind+1, tranNo+1, prices, n,k,dp),
                                                   0 + f(ind+1, tranNo, prices, n,k,dp));
        }
    }*/
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        vector<int>cur(2*k+1, 0), after(2*k+1,0);


        for(int ind=n-1; ind>=0; ind--) {
            for(int tranNo = 2*k-1; tranNo>=0; tranNo--) {
                if(tranNo%2==0) {
                    cur[tranNo] = max(-prices[ind] + after[tranNo+1],
                                                     0 + after[tranNo]);
                }
                else {
                    cur[tranNo] = max(prices[ind] + after[tranNo+1],
                                                        0 + after[tranNo]);
                }
            }
            after = cur;
        }
        return after[0];
    }
};