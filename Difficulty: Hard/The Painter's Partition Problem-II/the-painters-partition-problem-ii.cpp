class Solution {
  public:
    int countSub(vector<int> &arr, int num) {
        int loadNum = 0;
        int subSeq = 1;
        for(int i=0; i<arr.size(); i++) {
            if(loadNum + arr[i] <= num) {
                loadNum += arr[i];
            }
            else {
                loadNum = arr[i];
                subSeq++;
            }
        }
        
        return subSeq;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(),0);
        
        while(l<=h) {
            int mid = l+(h-l)/2;
            int subseque = countSub(arr,mid);
            if(subseque > k) l = mid+1;
            else h = mid-1;
        }
        
        return l;
    }
};