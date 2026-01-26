class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(sum%2 != 0) return false; // here was your error
        int k = sum/2;
        vector<bool>prev(k+1,0), cur(k+1,0);

        prev[0] = cur[0] = true;

        if(nums[0] <= k) prev[nums[0]] = true;

        for(int ind=1; ind<n; ind++) {
            for(int target=1; target<=k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(nums[ind] <= target) {
                    take = prev[target-nums[ind]];
                }
                cur[target] = take || notTake;
            }
            prev = cur;
        }

        return prev[k];
    }
};