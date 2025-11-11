class Solution {
public:
    char findTheDifference(string s, string t) {
        char result=0;
        for(char ch1:s) result^=ch1;
        for(char ch2:t) result^=ch2;
        return result;
    }
};
