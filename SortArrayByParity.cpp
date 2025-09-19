class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int cntEven=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
            cntEven++;
        }
        int i=0;
        int j=cntEven;
        while(i<cntEven && j<n){
            if(nums[i]%2==0)
               i++;
            else if(nums[j]%2==1)
               j++;
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        return nums;
    }
};
