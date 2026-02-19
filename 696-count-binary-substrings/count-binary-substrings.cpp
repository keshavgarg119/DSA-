class Solution {
public:
    int countBinarySubstrings(string s) {
        int currRun = 1, prevRun = 0;
        int ans = 0;
        for(int i=1; i<s.length(); i++) {
            if(s[i]==s[i-1]) {
                currRun++;
            }
            else {
                ans += min(currRun, prevRun);
                prevRun = currRun;
                currRun = 1;
            }
        }

        ans += min(prevRun, currRun);

        return ans;
    }
};