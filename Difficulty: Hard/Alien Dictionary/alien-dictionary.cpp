class Solution {
  public:
  
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i])
                indegree[it]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        if(topo.size() != V)
            return {}; 
        
        return topo;
    }
    
    string findOrder(vector<string> &words) {
        int N = words.size();
        vector<int> adj[26]; 
        unordered_set<char> uniqueChars;
        
        for (auto &w : words)
            for (char c : w)
                uniqueChars.insert(c);
        
        for(int i = 0; i < N - 1; i++) {
            string str1 = words[i];
            string str2 = words[i + 1];
            
            int len = min(str1.size(), str2.size());
            bool foundDiff = false;
            
            for(int j = 0; j < len; j++) {
                if(str1[j] != str2[j]) {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    foundDiff = true;
                    break;
                }
            }
            if(!foundDiff && str1.size() > str2.size())
                return "";
        }
        
        vector<int> topo = topoSort(26, adj);
        if(topo.empty()) return ""; 
        
        string ans = "";
        for(auto it : topo) {
            char c = it + 'a';
            if(uniqueChars.count(c))
                ans += c;
        }
        
        return ans;
    }
};
