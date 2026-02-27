class Solution {
public:
    int recursive(vector<vector<int>>& obstacleGrid,int row,int col,vector<vector<int>>&dp){
        if(row<0 || col<0){
            return 0;
        }
        if(obstacleGrid[row][col]== 1){
            return 0;
        }
        if(row==0 && col==0){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int up=recursive(obstacleGrid,row-1,col,dp);
        int left=recursive(obstacleGrid,row,col-1,dp);

        return dp[row][col]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        
        vector<vector<int>>dp(r,vector<int>(c,-1));
        
        return recursive(obstacleGrid,r-1,c-1,dp);;
    }
};
