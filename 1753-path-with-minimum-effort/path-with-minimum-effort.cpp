class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,
         vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int r = top.second.first;
            int c = top.second.second;
            int d = top.first;

            if(r==n-1 && c==m-1) return d;
            for(int i=0; i<4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int newEffort = max(abs(heights[nr][nc] - heights[r][c]), d);
                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({dist[nr][nc], {nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};