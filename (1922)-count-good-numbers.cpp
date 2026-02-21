class Solution {
public:
    const long long MOD=1e9+7;

    long long power(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp % 2 == 1){
                res=(res * base)%MOD;
            }
            base=(base*base) % MOD;
            exp=exp/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        
        long long even_p=(n+1)/2;
        long long prime_p=n/2;

        long long even=power(5,even_p);
        long long prime=power(4,prime_p);

        return (even * prime) % MOD;
    }
};
