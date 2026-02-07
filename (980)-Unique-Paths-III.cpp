class Solution {
public:
    void path(vector<vector<int>>&grid,int i,int j,int &res,vector<vector<int>>&choosen,int zeros){
        if(grid[i][j]==2){
            if(zeros==-1){
                res++;
            }
            return;
        }
        int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
        for(auto d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni>=0 && nj>=0 && 
            ni<grid.size() && nj<grid[0].size() && 
            choosen[ni][nj]==0 && 
            (grid[ni][nj]==0 || grid[ni][nj]==2)){

                choosen[ni][nj]=1;
                path(grid,ni,nj,res,choosen,zeros-1);
                choosen[ni][nj]=0;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>>choosen(grid.size(),vector<int>(grid[0].size(),0));
        int res=0;
        int st_i;
        int st_j;
        int count_0=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    st_i=i;
                    st_j=j;
                }
                else if(grid[i][j]==0) count_0++;
            }
        }
        path(grid,st_i,st_j,res,choosen,count_0);
        return res;
    }
};
