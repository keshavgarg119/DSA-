class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>dpMin(n,0), dpMax(n,0);
        
        dpMin[0] = arr[0];
        dpMax[0] = arr[0];
        int ans = arr[0];
        
        for(int i=1; i<n; i++) {
            dpMin[i] = min(arr[i], min(dpMax[i-1]*arr[i], dpMin[i-1]*arr[i]));
            
            dpMax[i] = max(arr[i], max(dpMax[i-1]*arr[i], dpMin[i-1]*arr[i]));
            
            ans = max(ans, dpMax[i]);
        }
        
        return ans;
    }
};