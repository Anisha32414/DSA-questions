class Solution {
public:
    int mirrorDistance(int n) {
        int num=0;
        int dummy=n;
        while(dummy>0){
            int rem=dummy%10;
            num=num*10+rem;
            dummy=floor(dummy/10);

        }
        return abs(n-num);
    }
};
