class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int res=arr[0];
        int maxelem=arr[0];
        if(n<2)return res;
        for(int i=1;i<n;i++){
            maxelem=max(maxelem+arr[i],arr[i]);
            res=max(res,maxelem);
        }
        return res;
    }
};
