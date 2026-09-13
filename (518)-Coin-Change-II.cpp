class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long>dp(amount+1,0);
        dp[0]=1;
        for(int coin:coins){
            for(int t=coin;t<=amount;t++){
                if(dp[t]>INT_MAX-dp[t-coin]){
                    dp[t]=INT_MAX;
                }
                else{
                    dp[t]+=dp[t-coin];
                }
            }
        }
        return dp[amount];
    }
};
