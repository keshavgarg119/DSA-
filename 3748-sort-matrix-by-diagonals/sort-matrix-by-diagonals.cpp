class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        for (int k = n - 2; k >= 0; --k) {

            int i = k, j = 0;
            vector<int> t;
            while (i < n && j < n) {
                t.push_back(grid[i++][j++]);
            }
            sort(t.begin(), t.end(), greater<int>());

            i = k; j = 0;
            for (int x : t) {
                grid[i++][j++] = x;
            }
        }

        for (int k = 1; k < n; ++k) {

            int i = 0, j = k;
            vector<int> t;
            while (i < n && j < n) t.push_back(grid[i++][j++]);
            sort(t.begin(), t.end());

            i = 0; j = k;
            for (int x : t)  {
                grid[i++][j++] = x;
            }
        }
        return grid;
    }
};
