class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                res=res+nums[i];
            }
            else
              res=0;
            count=max(count,res);   
        }
        return count;
    }
};
