class Solution {
public:
/*
    int f(int i, int j, vector<vector<int>>&matrix) {
        if(j<0 || j>=matrix[0].size()) return -1e8;
        if(i==0) return matrix[0][j];

        int u = matrix[i][j] + f(i-1, j, matrix);
        int ld = matrix[i][j] + f(i-1, j-1, matrix);
        int rd = matrix[i][j] + f(i-1, j+1, matrix);

        return  min(u, max(rd,ld));
    }
*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0), cur(m,0);

        for(int j=0; j<m; j++) {
            prev[j] = matrix[0][j];
        }   

        for(int i=1 ; i<n; i++) {
            for(int j=0; j<m; j++) {
                int u = matrix[i][j] + prev[j];
                
                int ld = matrix[i][j];
                if(j-1>=0) ld += prev[j-1];
                else ld += 1e8;

                int rd = matrix[i][j];
                if(j+1<m) rd += prev[j+1];
                else rd += 1e8;

                cur[j] = min(u, min(ld, rd)); 
            }
            prev = cur;
        }

        int maxi = 1e8;
        for(int j=0; j<m; j++) {
            maxi = min(maxi, prev[j]);
        }
        return maxi;
    }
};