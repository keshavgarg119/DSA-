class Solution {
public:
    /*int f(int i, int j, string &s, string &t, vector<vector<int>>&dp) {
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        
        return dp[i][j] = f(i-1,j,s,t,dp);
    }*/
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        const long long LIM = LLONG_MAX;

        for (int i = 1; i <= n; i++) {
            for (int j = min(i, m); j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    if (dp[j] > LIM - dp[j - 1])
                        dp[j] = LIM;          
                    else
                        dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m];
    }


};

// This is the code written by me
/*int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }*/