class Solution {
public:
    int maxOperations(string s) {
        int res = 0;
        int block = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            block += (s[i] - '0');
            if (i > 0 && s[i] < s[i-1]) {
                res += block;
            }
        }
        return res;
    }
};
