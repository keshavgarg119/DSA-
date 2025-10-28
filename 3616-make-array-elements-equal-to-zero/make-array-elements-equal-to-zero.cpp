class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        for(int i: nums) {
            right += i;
        }

        for(int i: nums) {

            if(i == 0) {

                if(left >= right && left-right <= 1) {
                    count++;
                }

                if(right >= left && right-left <= 1) {
                    count++;
                }
            }

            left += i;
            right -= i;
        }
        return count;
    }
};