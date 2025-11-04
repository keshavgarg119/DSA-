class Solution {
public:

    vector<int>ans;

    void dfs(int curr, int n) {
        if(curr > n) return;
        ans.push_back(curr);

        int next = 0;
        
        for(int i=0; i<=9; i++) {
            next = curr*10 + i;
            if(next > n) return;
            dfs(next, n); 
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i<=9; i++) {
            dfs(i,n);
        }
        return ans;
    }
};