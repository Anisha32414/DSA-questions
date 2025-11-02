class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,0));

        for(auto &w:walls) mat[w[0]][w[1]]=1;
        for(auto &g:guards) mat[g[0]][g[1]]=2;

        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        for(auto &g:guards){
            for(auto &d:dir){
                int x=g[0]+d[0];
                int y=g[1]+d[1];
                while(x>=0 && x<m && y>=0 && y<n && mat[x][y]!=1 && mat[x][y]!=2){
                    if(mat[x][y]==0){
                        mat[x][y]=3;
                    }
                    x+=d[0];
                    y+=d[1];
                }
            }
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)
                   count++;
            }
        }
        return count;
    }
};
