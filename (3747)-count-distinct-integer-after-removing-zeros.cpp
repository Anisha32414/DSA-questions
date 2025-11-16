class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int L = s.size();

        long long p9[20];
        p9[0] = 1;
        for (int i = 1; i < 20; i++) p9[i] = p9[i - 1] * 9;

        long long ans = 0;

   
        for (int i = 1; i < L; i++) {
            ans += p9[i];  
        }

        for (int i = 0; i < L; i++) {
            int digit = s[i] - '0';

            if (digit == 0) {
                break; 
            }
            int choices = digit - 1;

            ans += (long long)choices * p9[L - i - 1];

            if (i == L - 1) {
                ans++; 
            }
        }

        return ans;
    }
};
