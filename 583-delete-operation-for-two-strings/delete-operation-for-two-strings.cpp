class Solution {
public:
    int lcs(string &word1, string &word2, int n, int m) {
        vector<int>prev(m+1,0), cur(m+1,0);

        for(int j=0; j<=m; j++) prev[j] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(cur[j-1], prev[j]); 
            }
            prev = cur;
        }

        return cur[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        return n + m - 2*lcs(word1,word2, n, m);
    }
};