class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(grid.size(),vector<int>(grid.size(),INT_MAX));
        dist[0][0]=1;

        queue<pair<int,int>>q;
        q.push({0,0});
        int dr[]={0,1,0,-1,-1,1,1,-1};
        int dc[]={1,0,-1,0,1,1,-1,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(r==n-1 && c==n-1) return dist[n-1][n-1];
            for(int i=0;i<8;i++){
                int row=r+dr[i];
                int col=c+dc[i];

                if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==0 && dist[row][col]==INT_MAX){
                    dist[row][col]=dist[r][c]+1;
                    q.push({row,col});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};
