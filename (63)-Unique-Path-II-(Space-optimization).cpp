class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();

        vector<int>prev(c,0);
        for(int i=0;i<r;i++){
            vector<int>temp(c,0);
            for(int j=0;j<c;j++){
                if(obstacleGrid[i][j]==1) temp[j]=0;

                else if(i==0 && j==0) temp[0]=1;
                
                else{
                    int up=prev[j];
                    int left=(j>0)?temp[j-1]:0;

                    temp[j]=up+left;
                }
            }
            prev=temp;
        }
        return prev[c-1];
    }
};
