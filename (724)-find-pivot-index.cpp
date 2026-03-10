class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long left=0;
        long long right=0;

        for(int n:nums){
            right+=n;
        }

        for(int i=0;i<nums.size();i++){
            right-=nums[i];
            if(left==right) return i;
            left+=nums[i];
        }
        return -1;
    }
};
