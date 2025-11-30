class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        string s1="";
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
                s1+=s[i];
            }
        }
        string rev_str=s1;
        reverse(rev_str.begin(),rev_str.end());
        return rev_str==s1;
    }
};
