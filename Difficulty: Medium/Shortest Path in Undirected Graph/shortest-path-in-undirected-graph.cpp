class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int v = adj.size();
        vector<int>dist(v,-1);
        queue<int>q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(dist[it] == -1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
};