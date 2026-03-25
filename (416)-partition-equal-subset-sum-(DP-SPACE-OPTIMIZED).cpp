class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int n:nums) total+=n;
        if(total%2==1) return false;

        int target=total/2;
        vector<bool>prev(target+1,0),curr(target+1,0);
        prev[0]=curr[0]=true;

        if(nums[0]<=target)
        prev[nums[0]]=true;

        for(int i=1;i<nums.size();i++){
            for(int t=1;t<=target;t++){
                bool not_take=prev[t];
                bool take=false;
                if(t>=nums[i]){
                    take=prev[t-nums[i]];
                }
                curr[t]=take || not_take;
            }
            prev=curr;
        }
        return prev[target];
    }
};
