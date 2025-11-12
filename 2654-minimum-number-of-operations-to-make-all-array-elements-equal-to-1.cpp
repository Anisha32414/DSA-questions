class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1=count(nums.begin(),nums.end(),1);

        if(count1>0) return nums.size()-count1;

        int gcd_val=nums[0];
        for(int i=1;i<nums.size();i++){
            gcd_val=gcd(gcd_val,nums[i]);
        }

        if(gcd_val!=1) return -1;

        int minLen=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int gcd_value=nums[i];
            for(int j=i+1;j<nums.size();j++){
                gcd_value=gcd(gcd_value,nums[j]);
                if(gcd_value==1){
                    minLen=min(minLen,j-i+1);
                    break;
                }
            }
        }
        return (minLen-1)+(nums.size()-1);
    }
};
