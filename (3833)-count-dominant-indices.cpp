class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int count=0;
        for(int i=1;i<n;i++)sum+=nums[i];
        for(int i=0;i<n-1;i++){
            int right_count=n-i-1;
            if(double(sum/right_count)<nums[i]) count++;

            sum-=nums[i+1];
        }
        return count;
    }
};
