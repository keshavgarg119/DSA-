class Solution {
  public:
    /*void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        // Convert edge list -> adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);  // directed edge u -> v
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
    */
    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        //Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }
};
