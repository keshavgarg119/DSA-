class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int m = nums.size();
        int j=0, maxi=1;
        for(int i=0; i<m; i++) {
            while(j<m && 1LL*nums[j]<= 1LL*nums[i]*k) {
                j++;
            }
            maxi = max(maxi, j-i);
        }
        return m-maxi;
    }
};
