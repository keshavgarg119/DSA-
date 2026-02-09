class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>ansRow;
        long long ans = 1;
        ansRow.push_back(1);

        for(int col=0; col<rowIndex; col++) {
            ans = ans*(rowIndex-col);
            ans = ans/(col+1);
            ansRow.push_back(ans);
        
        }
        
        return ansRow;
        
    }
};