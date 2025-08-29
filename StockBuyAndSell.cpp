class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int res=0;
        for(int i=0;i<n-1;i++){
            if(prices[i+1]>prices[i]){
                  res+=(prices[i+1]-prices[i]);
            }
        }
        return res;
    }
};
