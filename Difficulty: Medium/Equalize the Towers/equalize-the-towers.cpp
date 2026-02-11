class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = cost.size();
        
        int totalWeight = 0;
        
        
        vector<pair<int,int>>tower;
        for(int i=0; i<n; i++) {
            totalWeight += cost[i];
            tower.push_back({heights[i], cost[i]});
        }
        
        sort(tower.begin(), tower.end());
        long long commulativeW = 0;
        int targetHeight = 0;
        for(int i=0; i<n; i++) {
            commulativeW += tower[i].second;
            if(commulativeW >= (totalWeight+1)/2) {
                targetHeight = tower[i].first;
                break;
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            ans += abs(heights[i] - targetHeight)*cost[i];
        }
        
        return ans;
        
    }
};
