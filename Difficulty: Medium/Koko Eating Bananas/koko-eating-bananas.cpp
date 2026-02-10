class Solution {
  public:
  
    int findMax(vector<int>& arr) {
        int maxi = 0;
        for(int i=0; i<arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
    
    int calculateTotal(vector<int>& arr, int hour) {
        int total = 0;
        
        for(int i=0; i<arr.size(); i++) {
            total += ceil((double)arr[i]/double(hour));
        }
        
        return total;
    }
    
    
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int l=1, h=findMax(arr);
        
        while(l<=h) {
            int mid = l + (h-l)/2;
            int totalH = calculateTotal(arr,mid);
            
            if(totalH<=k) {
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return l;
        
    }
};