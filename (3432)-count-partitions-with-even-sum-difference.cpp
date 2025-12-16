class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        int count=0;
        int leftSum=0;

        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            int rightSum=sum-leftSum;
            if(leftSum%2==rightSum%2) count++;
        }
        return count;
        
        /*                                                        //another method
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2==0) return n-1;
        else return 0;
        */
    }
};
