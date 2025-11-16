class Solution {
public:
    int numSub(string s) {
        long long ans=0,count=0;
        long long mod=1e9+7;

        for(char c:s){
            if(c=='1')
                count++;
            else{
                ans=(ans+count*(count+1)/2)%mod;
                count=0;
            }
        }
        ans=(ans+count*(count+1)/2)%mod;
        return ans;
    }
};
