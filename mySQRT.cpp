class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        if(x==0 || x==1) return x;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long i=mid*mid;
            if(i<=x){
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return right;
    }
};
