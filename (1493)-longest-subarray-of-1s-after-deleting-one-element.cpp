class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeros=0;
        int res=-1;
        int l=0;
        int r=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0) zeros++;

            if(zeros>1){
                if(nums[l]==0) zeros--;
                l++;
            }
            res=max(res,r-l);
            r++;
        }
        return res;
    }
};
