class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
               
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc >=0 && nr<grid.size() && nc<grid[0].size()
                && grid[nr][nc]=='1' && visited[nr][nc]==0){
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                    
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    cnt++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};
