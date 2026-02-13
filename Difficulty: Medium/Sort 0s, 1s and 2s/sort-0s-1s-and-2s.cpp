class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int left=0, right=n-1, mid=0;
        
        while(mid<=right) {
            if(arr[mid]==0) {
                swap(arr[left], arr[mid]);
                left++;
                mid++;
            }
            else if(arr[mid]==2) {
                swap(arr[right], arr[mid]);
                right--;
            }
            else mid++;
        }
        
        
    }
};