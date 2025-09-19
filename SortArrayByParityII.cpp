class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=0,j=0;i<n;i++){
            if(nums[i]%2==0){
                res[j]=nums[i];
                j=j+2;
            }
        }
        for(int i=0,j=1;i<n;i++){
            if(nums[i]%2!=0){
                res[j]=nums[i];
                j=j+2;
            }
        }
        return res;
    }
};
