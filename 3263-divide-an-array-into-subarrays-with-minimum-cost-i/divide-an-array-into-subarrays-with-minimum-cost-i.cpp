class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        vector<int>temp(n);
        for(int i=1; i<n; i++) {
            temp[i] = nums[i];
        }
        sort(temp.begin(), temp.end());
        int s1 = temp[1];
        int s2 = temp[2];

        return s1+s2+nums[0];
    }
};