class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2) {
            string t;
            for(int i = 0; i+1<s.size(); i++) {
                int d1 = s[i] - '0';
                int d2 = s[i+1] - '0';
                int sumMod = (d1 + d2)%10;
                t.push_back(char(sumMod + '0')); 
            }
            s = move(t);
        }

        return s[0] == s[1];
    }
};