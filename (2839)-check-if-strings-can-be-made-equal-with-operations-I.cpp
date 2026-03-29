class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2)return true;

        string dummy=s1;
        swap(dummy[0],dummy[2]);
        if(dummy==s2) return true;

        dummy=s1;
        swap(dummy[1],dummy[3]);
        if(dummy==s2) return true;

        swap(dummy[0],dummy[2]);
        if(dummy==s2) return true;
        return false;
    }
};
