class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum=0;
        for(int x:nums) total_sum+=x;

        if(total_sum<abs(target)) return 0;

        if((total_sum+target)%2!=0) return 0;

        int tar=(total_sum+target)/2;

        vector<int>dp(tar+1,0);
        dp[0]=1;

        for(int num:nums){
            for(int i=tar;i>=num;i--){
                dp[i]+=dp[i-num];
            }
        }
        return dp[tar];
    }
};
