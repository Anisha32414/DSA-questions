class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        int res=1;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int j=0;j<n;j++){
            while(1LL*nums[j]>1LL*nums[i]*k){
                i++;
            }
            res=max(res,j-i+1);
        }
        return n-res;
    }
};
