class Solution {
public:
    bool sameDigits(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        if (s1.size() != s2.size())
            return false;
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        return s1 == s2;
    }
    
    bool isDigitorialPermutation(int n) {
        vector<int> digitorials = {1, 2, 145, 40585};
        
        for (int x : digitorials)
            if (sameDigits(n, x))
                return true;
        
        return false;
    }
};
