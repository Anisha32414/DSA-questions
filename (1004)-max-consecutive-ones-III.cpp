class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0;
        int l=0;
        int n=nums.size();
        int res=-1;
        int zero=0;
        while(r<n){
            if(nums[r]==0) zero++;

            if(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }

            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
