class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        int curr;
        if(n==first) return first;
        if(n==second) return second;
        for(int i=3;i<=n;i++){
            curr=first+second;
            first=second;
            second=curr;
        }
        return second;
    }
};
