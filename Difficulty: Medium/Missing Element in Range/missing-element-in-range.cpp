class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> result;

        int n = arr.size();
        int current = low;

        for (int i = 0; i < n; i++) {

            if (arr[i] < low)
                continue;

            if (arr[i] > high)
                break;

            while (current < arr[i]) {
                result.push_back(current);
                current++;
            }

            if (current == arr[i])
                current++;
        }

    
        while (current <= high) {
            result.push_back(current);
            current++;
        }

        return result;
    }
};
