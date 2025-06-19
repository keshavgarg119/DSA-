// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start = 0;
        int end = arr.size()-1;
        int n = arr.size();
        while(start <= end) {
            
            if (arr[start] <= arr[end]) {
                return start;
            }
            
            int mid = start+(end-start)/2;
            int next = (mid+1)%n;
            int prev = (mid+n-1)%n;
            // we done the formula prev and next index becuse of the circular locations
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]) {
                return mid;           // checked wheather the mid element is the smallest 
            }
            
            if(arr[mid] >= arr[start]) {
                start = mid+1;            // chosing the direction for the further iterations
            }
            else {
                end = mid-1;
            }
            
        }
        return 0;
    }
};
