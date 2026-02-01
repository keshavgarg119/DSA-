class Solution {
public:
    /*int f(int i, int j, string &t1, string &t2, vector<vector<int>>&dp) {
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(t1[i] == t2[j]) return 1 + f(i-1, j-1, t1, t2,dp);

        return dp[i][j] = max(f(i-1,j,t1,t2,dp), f(i,j-1,t1,t2,dp));
    }*/
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        //vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>prev(m+1, 0), cur(m+1,0);

        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return cur[m];
    }
};