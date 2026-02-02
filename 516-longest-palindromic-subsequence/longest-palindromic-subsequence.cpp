class Solution {
public:
    int lcs(string &s, string &t, int n) {
    
        //vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int>prev(n+1,0), cur(n+1, 0);

        //for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) prev[j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == t[j-1]) {
                    cur[j] = 1 + prev[j-1];
                }
                else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }

        return cur[n];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        string t = s;
        reverse(s.begin(), s.end()); // lcs of the string and reverse of it is palindromic lcs
        return lcs(s,t,n);
    }
};