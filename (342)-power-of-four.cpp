class Solution {
public:
    bool isPowerOfFour(int n) {
        long long dummy=1;
        while(1){
            if(dummy==n) return true;
            if(dummy>n) return false;
            dummy*=4;
        }
        return false;
    }
};
