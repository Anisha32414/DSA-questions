class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = 0;

        for(char c : s) {
            if(c == '1') ones++;
        }
        
        int result = n;
        result = min(result, ones);
        result = min(result, n - ones);
        if(ones > 0)
            result = min(result, ones - 1);
        else
            result = min(result, 1);
        if(n >= 2) {
            int cost = 0;
            if(s[0] == '0') cost++;
            if(s[n - 1] == '0') cost++;
            for(int i = 1; i < n - 1; i++) {
                if(s[i] == '1') cost++;
            }
            result = min(result, cost);
        }
        return result;
    }
};
