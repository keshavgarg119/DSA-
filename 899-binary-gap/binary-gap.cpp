class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;        // previous 1 position
        int maxDist = 0;      // answer
        int index = 0;        // current bit position
        
        while (n > 0) {
            if (n & 1) {      // if last bit is 1
                if (prev != -1) {
                    maxDist = max(maxDist, index - prev);
                }
                prev = index;
            }
            n = n >> 1;       // shift right
            index++;
        }
        
        return maxDist;
    }
};