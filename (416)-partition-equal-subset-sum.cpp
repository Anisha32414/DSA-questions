class Solution {
public:
    bool partition(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(target<0 || index>=nums.size()) return false;

        if(dp[index][target]!=-1) return dp[index][target];

        bool take=partition(nums,index+1,target-nums[index],dp);
        bool not_take=partition(nums,index+1,target,dp);

        return dp[index][target]=(take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int n:nums) total+=n;
        if(total%2==1) return false;

        int target=total/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return partition(nums,0,target,dp);
    }
};
