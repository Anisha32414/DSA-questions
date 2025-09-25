class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        sort(nums.begin(),nums.end());
        
        for(int i=n-2;i>=0  ;i--){
            if(nums[i]==nums[i+1])  
                continue;
            if(nums[i]!=nums[i+1]){
                count++;
                if(count==3)
                   return nums[i];
            }
        }
        return nums[n-1];
    }
};
