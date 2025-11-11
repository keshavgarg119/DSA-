class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& graph, 
                  vector<int>& pathVis, vector<int>& vis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : graph[node]) {
            if(!vis[it]) {
                if(dfsCheck(it, graph, pathVis, vis, check)) return true;
            } 
            else if(pathVis[it]) {
                return true; // cycle found
            }
        }

        check[node] = 1;  
        pathVis[node] = 0;  
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pathVis(n, 0), vis(n, 0), check(n, 0);

        for (int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfsCheck(i, graph, pathVis, vis, check);
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if(check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

