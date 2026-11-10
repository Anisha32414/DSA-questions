class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int res=-1;
        int zeros=0;
        while(r<n){
            if(nums[r]==0) zeros++;

            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }

            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
