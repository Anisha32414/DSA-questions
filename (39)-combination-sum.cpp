class Solution {
public:
    void combination_sum_I(int index,vector<int>&arr,int k,int &sum,vector<int>&dummy,vector<vector<int>>&res){
        if(sum>=k || index==arr.size()){
            if(sum==k){
                res.push_back(dummy);
        }
        return;
    }
    dummy.push_back(arr[index]);
    sum+=arr[index];
    combination_sum_I(index,arr,k,sum,dummy,res);

    dummy.pop_back();
    sum-=arr[index];
    combination_sum_I(index+1,arr,k,sum,dummy,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>>res;
        int sum=0;
        vector<int>dummy;
        combination_sum_I(0,candidates,target,sum,dummy,res);
        return res;
    }
};
