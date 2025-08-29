class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int x=arr.size();
        sort(arr.begin(),arr.end());
        int res=arr[x-1]-arr[0];
        for(int i=0;i<x-1;i++){
            if(arr[i+1]-k<0)
              continue;
            int minh=min(arr[0]+k,arr[i+1]-k);
            int maxh=max(arr[i]+k,arr[x-1]-k);
            res=min(res,maxh-minh);
        }
        return res;
    }
};
