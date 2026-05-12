class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        int mid=left+(right-left)/2;
        while(left<right){
            if (nums[mid]==target)
               return mid;
            else if(nums[mid]>target)
               right=mid-1;
            else
               left=mid+1;
            mid=left+(right-left)/2;
        }
        if(left==right){
            if(nums[mid]>target)
               return mid;
            else if(nums[mid]<target)
               return mid+1;
        }

        return mid;
    }
};
