class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int flag=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && flag==0){
               flag=1;
            }
            else if(s[i]=='0' && flag==1){
                flag=2;
            }
            else if(s[i]=='1' && flag==2){
                return false;
            }
        }
        return true;
    }
};
