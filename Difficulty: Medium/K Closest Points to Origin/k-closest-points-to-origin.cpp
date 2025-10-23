class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<int, pair<int,int>>> mp;
        
        for(auto &p : points) {
            int a = p[0];
            int b = p[1];
            int dist = a*a+b*b;
            
            mp.push({dist,{a,b}});
            
            if(mp.size() > k) mp.pop();
        }
        
        vector<vector<int>>result;
        while(!mp.empty()) {
            auto top = mp.top();
            mp.pop();
            result.push_back({top.second.first, top.second.second});
        }
        
        return result;
    }
};

        