class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        
        // Step 1: Extract words
        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);  // last word

        // Step 2: Reverse the words
        reverse(words.begin(), words.end());

        // Step 3: Join them with space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};
