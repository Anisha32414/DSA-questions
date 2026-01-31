class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();

        if(n<3) return 0;

        while(start<end && nums[start]==nums[0]){
            start++;
        }
        while(end>=0 && nums[end]==nums[n-1]){
            end--;
        }
        return max(0,end-start+1);
    }
};
