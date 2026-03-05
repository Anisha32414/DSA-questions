class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string pat1, pat2;
        bool one = false;

        for(int i = 0; i < n; i++){
            if(one) pat1.push_back('1');
            else pat1.push_back('0');
            one = !one;
        }

        one = true;
        for(int i = 0; i < n; i++){
            if(one) pat2.push_back('1');
            else pat2.push_back('0');
            one = !one;
        }

        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] != pat1[i]) cnt1++;
            if(s[i] != pat2[i]) cnt2++;
        }

        return min(cnt1, cnt2);
    }
};
