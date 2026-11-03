class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int max_ele=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            sum+=abs(nums[i]-max_ele);
        }
        return sum;
    }
};
