class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans(nums.size());
        int current_bit=0;
        for(int i=0;i<nums.size();i++){
            current_bit=(current_bit*2 + nums[i])%5;
            ans[i]=(current_bit==0);
        }
        return ans;
    }
};
