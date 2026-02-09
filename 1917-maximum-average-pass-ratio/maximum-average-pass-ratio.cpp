class Solution {
public:
    /*double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        auto gain = [](int pass, int total) {
            return (double)(pass+1)/(total+1) - (double)(pass)/(total);
        };

        priority_queue<pair<double,pair<int,int>>>pq;

        for(auto &c : classes) {
            pq.push({gain(c[0],c[1]), {c[0],c[1]}});
        }

        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();

            int pass = top.second.first;
            int total = top.second.second;
            pass++;
            total++;

            pq.push({gain(pass,total),{pass,total}});
        }

        double sum = 0.0;

        while (!pq.empty()) {
            auto [gainVal, pr] = pq.top(); pq.pop();
            sum += (double)pr.first / pr.second;
        }
        
        return sum / classes.size();
    }*/
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        
        for(int i = 0; i < n; i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain, i});
        }

        while(extraStudents--){
            auto top = pq.top(); pq.pop();
            int idx = top.second;

            classes[idx][0]++;
            classes[idx][1]++;

            int pass = classes[idx][0];
            int total = classes[idx][1];
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain, idx});
        }

        double ans = 0.0;
        for(auto &c : classes){
            ans += (double)c[0] / c[1];
        }

        return ans / n;
    }
};