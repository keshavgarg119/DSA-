class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 1;

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> pq;
        
        pq.push({1,{0,0}});
        int dr[] = {-1,0,1,1,1,0,-1,-1};
        int dc[] = {1,1,1,0,-1,-1,-1,0};

        while(!pq.empty()) {
            auto top = pq.top();
            int r = top.second.first;
            int c = top.second.second;
            int d = top.first;
            pq.pop();

            if (r == n-1 && c == m-1) return d;
            if (d > dist[r][c]) continue;

            for(int i=0; i<8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc] > d+1 && grid[nr][nc]==0) {
                    dist[nr][nc] = d+1;
                    pq.push({d+1, {nr,nc}});
                }
            }
        }
        return -1;
    }
};