class Solution {
public:
    /*int f(int ind, int t, vector<int>& coins, vector<vector<int>>&dp) {
        if(ind == 0) {
            return (t % coins[0] == 0);
        }

        if(dp[ind][t] != -1) return dp[ind][t];
        //if(t % coins[ind] == 0) return t / coins[ind];

        long notTake = f(ind-1, t, coins, dp);
        long take = 0;
        if(t >= coins[ind]) take = f(ind, t-coins[ind], coins, dp);

        return dp[ind][t] = take + notTake;
    }*/

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        vector<int>prev(amount+1, 0), cur(amount+1, 0);

        for(int t=0; t<=amount; t++) {
            prev[t] = (t % coins[0] == 0);
        }

        for(int ind=1; ind<n; ind++) {
            for(int t=0; t<=amount; t++) {
                long notTake = prev[t];
                long take = 0;
                if(t >= coins[ind]) take = cur[t-coins[ind]];

                cur[t] = take + notTake;
            }
            prev = cur;
        }

        return prev[amount];
    }
};