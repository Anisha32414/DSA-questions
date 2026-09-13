class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,1e9);
       dp[0]=0;

       for(int t=1;t<=amount;t++){
           for(int coin:coins){
               if(coin<=t){
                   dp[t]=min(dp[t],1+dp[t-coin]);
               }
           }
       }
       if(dp[amount]>=1e9) return -1;
       return dp[amount];
    }
};
