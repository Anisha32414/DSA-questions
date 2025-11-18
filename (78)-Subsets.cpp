class Solution {
public:

    void printSubsets(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&arr){
        if(i>=nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        printSubsets(i+1,nums,ans,arr);
        arr.pop_back();
        printSubsets(i+1,nums,ans,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        printSubsets(0,nums,ans,arr);
        return ans;
    }
};
