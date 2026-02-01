class Solution {
  public:
  
    // helper function
    vector<string> solve(int i, int j, string &s1, string &s2,
                         vector<vector<int>> &dp,
                         vector<vector<vector<string>>> &dpStr) {
        
        if (i == 0 || j == 0) {
            return {""};
        }

        if (!dpStr[i][j].empty()) return dpStr[i][j];

        vector<string> res;

        if (s1[i-1] == s2[j-1]) {
            vector<string> temp = solve(i-1, j-1, s1, s2, dp, dpStr);
            for (string str : temp) {
                res.push_back(str + s1[i-1]);
            }
        }
        else {
            // explore both paths when equal
            if (dp[i-1][j] >= dp[i][j-1]) {
                vector<string> top = solve(i-1, j, s1, s2, dp, dpStr);
                res.insert(res.end(), top.begin(), top.end());
            }
            if (dp[i][j-1] >= dp[i-1][j]) {
                vector<string> left = solve(i, j-1, s1, s2, dp, dpStr);
                res.insert(res.end(), left.begin(), left.end());
            }
        }

        // remove duplicates (important)
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());

        return dpStr[i][j] = res;
    }

    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();

        // LCS length DP
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // DP for storing strings (replaces memo)
        vector<vector<vector<string>>> dpStr(n+1, vector<vector<string>>(m+1));

        return solve(n, m, s1, s2, dp, dpStr);
    }
};
