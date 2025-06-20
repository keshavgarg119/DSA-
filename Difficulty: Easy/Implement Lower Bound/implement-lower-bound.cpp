// User function Template for C++
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int start = 0;
        int end = arr.size();
        int ans = arr.size();   // in case all the element are <= target
        while(start < end) {
            int mid = start+(end-start)/2;
            
            if(arr[mid] >= target) {
                ans = mid;
                end = mid;
            }
            else {
                start = mid+1;
            }
        }
        return ans;
    }
};
