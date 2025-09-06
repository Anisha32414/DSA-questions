class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector <int> res(n);
        int posind=0,negind=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[posind]=nums[i];
                posind+=2;
            }
            else{
                res[negind]=nums[i];
                negind+=2;
            }
        }
        return res;
    }
};
