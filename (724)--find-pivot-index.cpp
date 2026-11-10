class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0;
        for(int i:nums) total+=i;
        int prefix=0;
        int suffix=total;
        for(int i=0;i<nums.size();i++){
            suffix-=nums[i];
            if(prefix==suffix) return i;
            prefix+=nums[i];
        }
        return -1;
    }
};
