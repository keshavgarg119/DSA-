class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> freq;
        for(int x: arr) {
            freq[x]++;
        }
        
        vector<pair<int,int>> v;
        for(auto &it : freq) {
            v.push_back({it.first, it.second});
        }
        
        sort(v.begin(), v.end() , [](pair<int, int>&a, pair<int,int>&b) {
            if(a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        });
        
        vector<int>ans;
        for(int i=0; i<k && i<v.size(); i++) {
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};
