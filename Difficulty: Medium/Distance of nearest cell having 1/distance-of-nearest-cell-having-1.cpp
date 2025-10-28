class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,-1));
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            for(int k=0; k<4; k++) {
                int nx = dx[k] + x;
                int ny = dy[k] + y;
                if(nx>=0 && nx<=n-1 && ny>=0 && ny<= m-1 && dist[nx][ny]==-1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
};