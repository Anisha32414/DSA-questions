class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        vector<char> letters;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                letters.push_back(s[i]);
            }
        }
        int j = letters.size() - 1; 
        string res = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                res.push_back(letters[j--]);
            } else {
                res.push_back(s[i]); 
            }
        }

        return res;
    }
};
