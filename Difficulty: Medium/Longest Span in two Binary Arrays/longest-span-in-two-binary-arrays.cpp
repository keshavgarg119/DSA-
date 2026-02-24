class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        
        int n = a1.size();
        unordered_map<int, int> mp;  // prefixSum -> first index
        int prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            
            prefixSum += (a1[i] - a2[i]);
            
            // If prefix sum becomes 0, span is from 0 to i
            if(prefixSum == 0)
                maxLen = i + 1;
            
            // If seen before, update max length
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            }
            else {
                mp[prefixSum] = i;  // store first occurrence only
            }
        }
        
        return maxLen;
    }
};