class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' ')
               count++;
            if(count>0 && s[i]==' ')
               break;
        }
        return count;
    }
};
