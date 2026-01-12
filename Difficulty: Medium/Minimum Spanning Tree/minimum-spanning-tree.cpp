class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        // build adjacency list
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});

        int sum = 0;

        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for(auto &edge : adj[node]) {
                int adjNode = edge.first;
                int edjw = edge.second;

                if(!vis[adjNode]) {
                    pq.push({edjw, adjNode});
                }
            }
        }
        return sum;
    }
};
