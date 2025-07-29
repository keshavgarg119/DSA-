class Solution {
  public:
  
     // mid^n
    int power(int mid, int n) {
        int ans = 1;
        
        while(n>0) {
            if(n%2==1) {
                ans = ans*mid;
                n--;
            }
            else {
                mid = mid*mid;
                n = n/2;
            }
        }
        
        return ans;
    }
    
    // m^(1/n)
    int nthRoot(int n, int m) {
   
        int low = 0;
        int high = m;
        
        while(low<=high) {
            
            int mid = low + (high - low)/2;
            
            if(power(mid,n) == m) {
                return mid;
            }
            else if(power(mid,n) < m) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
            
        }
        
        return -1;
    }
};