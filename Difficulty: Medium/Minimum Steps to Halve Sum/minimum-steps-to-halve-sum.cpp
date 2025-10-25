class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double total = 0;
        
        for(int x: arr) {
            total += x;
        }
        priority_queue<double>pq;
        for(int x: arr) pq.push(x);
        
        int ops = 0;
        double currSum = total;
        double target = total/2.0;
        
        while(target < currSum) {
            double x = pq.top();
            pq.pop();
            
            currSum -= x/2.0;
            pq.push(x/2.0);
            ops++;
        }
        
        return ops;
    }
};