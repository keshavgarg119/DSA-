class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        int count = 1;
        int ans = -1;
        int i=0, j=0;
        
        while(i<n1 && j<n2) {
            if(a[i]<b[j]) {
                if(count == k) {
                    return a[i];
                }
                else {
                    i++;
                    count++;
                }
            }
            else {
                if(count == k) {
                    return b[j];
                }
                else {
                    j++;
                    count++;
                }
            }
        }
        
        while(i<n1) {
            if(count == k) {
               return a[i];
            }
            else {
                i++;
                count++;
            }
        }
        while(j<n2) {
            if(count == k) {
                return b[j];
            }
            else {
                j++;
                count++;
            }
        }
        
        return -1;
    }
};