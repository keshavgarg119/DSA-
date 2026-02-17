class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        sort(nums.begin()+1 , nums.end());
        int v = accumulate(nums.begin()+1 , nums.begin()+3 , 0);

        return ans+v;
        
    }
};