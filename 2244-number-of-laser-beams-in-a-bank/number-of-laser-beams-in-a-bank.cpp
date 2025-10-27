class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        
        for (string &row : bank) {
            int curr = count(row.begin(), row.end(), '1');
            if (curr > 0) {
                ans += prev * curr;
                prev = curr;
            }
        }
        return ans;
    }
};
