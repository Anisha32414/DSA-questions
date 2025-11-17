class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int count1=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(count1!=-1 && (i-count1-1)<k){
                    return false;
                }
            count1=i;
            }
        }
        return true;
    }
};
