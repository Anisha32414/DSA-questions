class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0){
                        up=dp[i-1][j];
                    }
                    if(j>0){
                        left=dp[i][j-1];
                    }
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[r-1][c-1];
    }
};
