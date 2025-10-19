class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        int n = s.size();
        unordered_set<string> seen;
        queue<string>q;
        seen.insert(s);
        q.push(s);

        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            if(curr < ans) ans = curr;

            string s1 = curr;
            for(int i=1; i<n; i+=2) {
                int digit = (s1[i] - '0' + a)%10;
                s1[i] = char('0' + digit);
            }

            if(!seen.count(s1)) {
                seen.insert(s1);
                q.push(s1);
            }
            
            string s2 = curr.substr(n-b) + curr.substr(0, n-b);
            if(!seen.count(s2)) {
                seen.insert(s2);
                q.push(s2);
            }
        }
        return ans;
    }
    
};