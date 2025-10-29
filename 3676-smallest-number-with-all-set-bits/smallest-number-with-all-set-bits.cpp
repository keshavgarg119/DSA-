class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        if(n==1) return 1;
        while(x < n) {
            x = x*2;
            if(x==n) {
                x = x*2;
            }
        }

        return x-1;
    }
};