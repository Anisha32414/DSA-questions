class Solution {
public:

    int squareNum(int num){
        int sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit*digit;
            num=num/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>mp;
        while(n!=1 && mp.count(n)==0){
            mp.insert(n);
            n=squareNum(n);
        }
        return n==1;
    }
};
