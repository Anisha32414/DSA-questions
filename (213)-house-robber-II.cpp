class Solution {
public:
    int house_robber(vector<int>&nums,int start,int end){
        if(start==end){
            return nums[start];
        }
        int first=nums[start];
        int second=max(nums[start],nums[start+1]);

        for(int i=start+2;i<=end;i++){
            int curr=max(nums[i]+first,second);
            first=second;
            second=curr;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int temp1=house_robber(nums,0,nums.size()-2);
        int temp2=house_robber(nums,1,nums.size()-1);
        return max(temp1,temp2);
    }
};
