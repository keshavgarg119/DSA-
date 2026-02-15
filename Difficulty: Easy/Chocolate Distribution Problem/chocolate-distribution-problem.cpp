class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        if(m==0 || n==0) return 0;
        if(n<m) return -1;
        
        sort(a.begin(), a.end());
        
        long long minDiff = INT_MAX;
        for(int i=0; i<=n-m; i++) {
            long long diff =  a[i+m-1] - a[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};