class Solution {
public:
    int path_sum(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0) return grid[row][col];
        if(row<0 || col<0) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];

        int up=INT_MAX; 
        int left=INT_MAX;
        if(row>0){
            up=path_sum(grid,row-1,col,dp);
        }
        if(col>0){
            left=path_sum(grid,row,col-1,dp);
        }
        return dp[row][col]=grid[row][col]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        
        return path_sum(grid,r-1,c-1,dp);;
    }
};
