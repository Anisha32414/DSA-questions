class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long n1=s.size();
        string res="";
        for(long long i=0;i<n1;i++){
            if(s[i]=='0') continue;
            res.push_back(s[i]);
        }

        if(res == "") return 0;
        
        long long long_num=stoll(res);
        long long dummy=long_num;
    
        long long sum=0;
        while(dummy>0){
            long long rem=dummy%10;
            sum=sum+rem;
            dummy/=10;
        }
        return 1LL*sum*long_num;    
    }
};
