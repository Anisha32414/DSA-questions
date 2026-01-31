class Solution {
public:
    void subset_sum(int index,vector<int>&arr,vector<int>&dummy,vector<vector<int>>&res){
        if(index==arr.size()){
            res.push_back(dummy);
            return;
        }
        dummy.push_back(arr[index]);
        subset_sum(index+1,arr,dummy,res);
        dummy.pop_back();
        while (index + 1 < arr.size() && arr[index] == arr[index + 1]) {
            index++;
        }
        subset_sum(index+1,arr,dummy,res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        int sum=0;
        vector<int>dummy;
        sort(nums.begin(),nums.end());
        subset_sum(0,nums,dummy,res);
        return res;
    }
};
