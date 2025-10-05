class Solution {
public:
  
    bool splitArray(vector<int>&nums,int mid,int k){
        int countarray=1;
        int subarraySum=0;
        for(int i=0;i<nums.size();i++){
            if(subarraySum+nums[i]>mid){
                countarray++;
                subarraySum=nums[i];
            }
            else{
                subarraySum+=nums[i];
            }
        }
        return countarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left= *max_element(nums.begin(),nums.end());
        int right=0;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            if(splitArray(nums,mid,k)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
