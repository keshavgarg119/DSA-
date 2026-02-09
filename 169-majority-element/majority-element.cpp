class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = 0;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(count == 0) {
                el = nums[i];
                count = 1;
            }
            else if(nums[i] == el) {
                count++;
            }
            else {
                count--;
            }
        }

        // we got the element and count how many times it appears
        int count1 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == el){
                count1++;
            }
        }
        if(count1 > nums.size()/2) {
            return el;
        }
        return -1;
    }
};