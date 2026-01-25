class Solution {
public:
    /*int f(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp, int n) {
        if(i == n-1){ 
            return triangle[n-1][j];
        }

        if(dp[i][j] != -1) return dp[i][j];
        int dg = triangle[i][j] + f(i+1,j+1,triangle,dp,n);
        int d = triangle[i][j] + f(i+1,j,triangle,dp,n);

        return dp[i][j] = min(dg,d);
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // without tabulaisation
        /*vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp,n);*/

        //vector<vector<int>>dp(n,vector<int>(n,0)); = vector<int>front(n,0)
        vector<int>front(n,0), cur(n,0);
        for(int j=0; j<n; j++) {
            front[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                cur[j] = min(d,dg);
            }
            front = cur;
        }

        return front[0];
    }
};