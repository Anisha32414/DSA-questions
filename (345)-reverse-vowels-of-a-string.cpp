class Solution {
public:
    bool isvowel(char ch){
        char c=tolower(ch);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(isvowel(s[i]) && isvowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isvowel(s[i]) && !isvowel(s[j])){
                j--;
            }
            else{
                i++;
            }
        }
        return s;
    }
};
