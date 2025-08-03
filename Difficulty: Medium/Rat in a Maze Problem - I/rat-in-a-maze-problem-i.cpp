class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& arr, int n, vector<string> &ans,
               vector<vector<int>> &vis, string move, int di[], int dj[]) {
        
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
                !vis[nexti][nextj] && arr[nexti][nextj] == 1) {
                
                vis[i][j] = 1;
                solve(nexti, nextj, arr, n, ans, vis, move + dir[ind], di, dj);
                vis[i][j] = 0;  
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();            
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[4] = {+1, 0, 0, -1};      
        int dj[4] = {0, -1, +1, 0};      
        
        if (maze[0][0] == 1) {
            solve(0, 0, maze, n, ans, vis, "", di, dj);
        }
        return ans;
    }
};
