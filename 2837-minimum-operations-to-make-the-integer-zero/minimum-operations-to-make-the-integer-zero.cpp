class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int k = 1; k <= 60; k++) {
            long long target = num1 - (long long)k * num2;
            if (target < 0) continue;

            int bits = __builtin_popcountll(target);
            if (bits <= k && k <= target) {
                return k;
            }
        }
        return -1;
    }
};