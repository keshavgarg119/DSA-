class Solution {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        //vector<int> dp(n, 0);
        int prev1 = 0;
        int prev2 = 0;
        
        prev2 = arr[0];
        prev1 = max(arr[0], arr[1]);

        for(int ind=2; ind<n; ind++) {
            int take = arr[ind] + prev2;
            int notTake = prev1;

            int cur = max(take, notTake);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int robStreet(int n, vector<int>&nums) {
        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> arr1, arr2;

        for(int i=0; i<n; i++) {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }

        int ans1 = solve(arr1);
        int ans2 = solve(arr2);

        return max(ans1, ans2);
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        return robStreet(n, nums);
    }
};