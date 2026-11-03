class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 +str1) return "";
        int l1=str1.size();
        int l2=str2.size();
        int gcdlen=gcd(l1,l2);
        return str1.substr(0,gcdlen);
    }
};
