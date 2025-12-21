class Solution {
public:
    int mirrorDistance(int n) {
        int num=0;
        int dummy=n;
        while(dummy>0){
            num=num*10+(dummy%10);
            dummy/=10;
        }
        return abs(num-n);
    }
};
