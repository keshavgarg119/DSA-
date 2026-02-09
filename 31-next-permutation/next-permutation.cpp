class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // find the dip here the next element is greter than the previous element
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        
        // if no such element is found then reverse the whole array
        if(index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the next greater element which is the smallest after the dip point
        for(int i=n-1; i>=index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        // reverse the suffix
        reverse(nums.begin()+index+1, nums.end());
    }
};