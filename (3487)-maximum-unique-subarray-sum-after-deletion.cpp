class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>mp;
        int res=INT_MIN;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0 && mp.find(nums[i])==mp.end()){
                sum+=nums[i];
                mp.insert(nums[i]);
            }
            else{
                res=max(res,nums[i]);
            }
        }
        if(sum==0 && mp.find(0)==mp.end()) return res;
        return sum;
    }
};
