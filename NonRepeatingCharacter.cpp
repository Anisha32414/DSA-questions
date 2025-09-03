
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        int n=s.size();
        int c,i;
        int frequency[256]={0};
        for(i=0;i<n;i++)
            frequency[(unsigned char)s[i]]++;
        for(i=0;i<n;i++){
            if(frequency[(unsigned char)s[i]]==1)
                return s[i];
        }
        return '$';
       
    }
};
