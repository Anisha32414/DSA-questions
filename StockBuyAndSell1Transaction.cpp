class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int res=0;
        int n=prices.size();
        int ele=prices[0];
        for(int i=0;i<n;i++){
            ele=min(ele,prices[i]);
            res=max(res,prices[i]-ele);
        }
        return res;
    }
};
