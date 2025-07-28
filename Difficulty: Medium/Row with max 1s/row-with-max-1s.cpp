// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m = arr[0].size();
        int n = arr.size();
        int j = m-1;
        int maxIndex = -1;
        
        for(int i=0; i<n; i++) {
            while(j>=0 && arr[i][j]==1) {
                j--;
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
};