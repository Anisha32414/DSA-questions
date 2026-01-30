class Solution {
public:
void combination_sum(int index,vector<int>&arr,int k,int &sum,vector<int>&dummy,vector<vector<int>>&res){
    if(sum>=k || index==arr.size()){
        if(sum==k){
           res.push_back(dummy);
        }
        return;
    }
  
    dummy.push_back(arr[index]);
    sum+=arr[index];
    combination_sum(index+1,arr,k,sum,dummy,res);

    dummy.pop_back();
    sum-=arr[index];

    while (index + 1 < arr.size() && arr[index] == arr[index + 1]) {
        index++;
    }
    combination_sum(index+1,arr,k,sum,dummy,res);
  
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>>res;
    int sum=0;
    vector<int>dummy;
    sort(candidates.begin(),candidates.end());
    combination_sum(0,candidates,target,sum,dummy,res);
    return res;
}
};
