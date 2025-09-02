class Solution {
  public:
    int myAtoi(string& s) {
        // code here
        int n=s.size();
        long num=0;
        int p=1;
        int i=0;
        while(i<n && s[i]==' ')i++;
        
        if(i<n && (s[i]=='-' || s[i]=='+'))
             if(s[i]=='-'){
                 p=-1;
                 i++;
             }
        
           for(;i<n && s[i]>='0' && s[i]<='9';i++){
                int digit=s[i]-'0';
                if(num>(INT_MAX-digit)/10){
                    return (p==-1)?INT_MIN:INT_MAX;
                }
               num=num*10+digit;
           }
           
           if(p==-1)
             return -num;
           else
             return num;
           
    }
};
