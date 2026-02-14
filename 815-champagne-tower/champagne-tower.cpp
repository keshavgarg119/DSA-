class Solution {
public:
    /*double f(int r, int c, vector<vector<double>>& dp, int poured) {
        if(c>r || c<0) return 0.0;
        if(r==0 && c==0) return poured;

        if(dp[r][c]!=-1.0) return dp[r][c];

        double left = f(r-1,c-1,dp,poured);
        double right = f(r-1,c,dp,poured);

        double fromLeft = max(0.0, (left-1.0)/2.0);
        double fromRight = max(0.0, (right-1.0)/2.0);

        return dp[r][c] = fromLeft + fromRight;

    }*/
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));

        dp[0][0] = poured;

        for(int r = 0; r <= query_row; r++) {
            for(int c = 0; c <= r; c++) {

                if(dp[r][c] > 1.0) {

                    double overflow = (dp[r][c] - 1.0) / 2.0;

                    dp[r+1][c]     += overflow;
                    dp[r+1][c + 1] += overflow;

                    dp[r][c] = 1.0;  
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }

};