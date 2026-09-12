class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1,0),curr(amount+1,0);

        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }

        for(int i=1;i<coins.size();i++){
            for(int t=0;t<=amount;t++){
                int not_take=0+prev[t];
                int take=INT_MAX;
                if(coins[i]<=t){
                    take=1+curr[t-coins[i]];
                }
                curr[t]=min(take,not_take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
