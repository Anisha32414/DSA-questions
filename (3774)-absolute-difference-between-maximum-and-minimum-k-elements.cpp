class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int count=0;
        int lsum=0;
        int rsum=0;
        while(1){
            if(count==k) break;
            lsum+=nums[l];
            rsum+=nums[r];
            l++;
            r--;
            count++;
        }
        return rsum-lsum;
    }
};
