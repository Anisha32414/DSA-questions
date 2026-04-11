class Solution {
public:
    bool is_prime(int num){
        if(num<=1) return false;
        if(num==2) return true;
        if(num%2==0) return false;
        for(int i=3;i*i<=num;i+=2){
            if(num%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int opr=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(i%2==0){
                while(!is_prime(num)){
                    opr++;
                    num++;
                }
            }
            else{
                while(is_prime(num)){
                    opr++;
                    num++;
                }
            }
        }
        return opr;
    }
};
