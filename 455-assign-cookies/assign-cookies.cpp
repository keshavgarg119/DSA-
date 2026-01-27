class Solution {
public:
    /*int f(int sInd, int gInd, int n, int m, vector<int>& g, vector<int>& s, vector<vector<int>>&dp) {

        if(sInd>=n || gInd>=m) return 0;
        if(dp[sInd][gInd] != -1) return dp[sInd][gInd];

        int result = 0;

        if(s[sInd] >= g[gInd]) {
            result = max(result, 1+f(sInd+1,gInd+1,n,m,g,s,dp));
        }
        result = max(result, f(sInd+1,gInd,n,m,g,s,dp));
        

        return dp[sInd][gInd] = result;
    }*/
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = s.size();
        int m = g.size();

        vector<int>next(m+1,0), cur(m+1,0);

        
        for(int si=n-1; si>=0; si--) {
            for(int gi=m-1; gi>=0; gi--) {

                int result = 0;
            
                if(s[si] >= g[gi]) {
                    result = 1+next[gi+1];
                }
                result = max(result, next[gi]);
                cur[gi] = result;
            }
            next = cur;
        }
        return next[0];*/
      
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int contentChildren = 0;
        int cookieIndex = 0;
        while (cookieIndex < s.size() && contentChildren < g.size()) {
            if (s[cookieIndex] >= g[contentChildren]) {
                contentChildren++;
            }
            cookieIndex++;
        }
        return contentChildren;
    }
};