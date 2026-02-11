class Solution {
public:
    int countSubSeq(vector<int>& nums, int num) {
        int subs = 1;
        int loadNum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(loadNum + nums[i] <= num) {
                loadNum += nums[i];
            }
            else {
                loadNum = nums[i];
                subs++;
            }
        }
        return subs;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high) {
            int mid = low+(high-low)/2;
            int subSeq = countSubSeq(nums, mid);
            if(subSeq > k) {
                low = mid + 1;
            }
            else high = mid-1;
        }
        return low;
    }
};