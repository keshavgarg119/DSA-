class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));
        // mark 0 = unguarded, 1 = guarded, 2 = occupied
        for(auto &g: guards) {
            grid[g[0]][g[1]] = 2;
        }

        for(auto &w: walls) {
            grid[w[0]][w[1]] = 2;
        }

        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for(auto &g: guards) {
            int r = g[0];
            int c = g[1];

            for(auto [dr,dc]: dir) {
                int nr = dr+r;
                int nc = dc+c;
                while(nr >= 0 && nr < m && nc >= 0 && nc < n &&  grid[nr][nc]!=2) {
                    if(grid[nr][nc] == 0) { // not occupied, marks as guarded
                        grid[nr][nc] = 1;
                    }
                    nr += dr;
                    nc += dc;
                }
            }
        }

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};