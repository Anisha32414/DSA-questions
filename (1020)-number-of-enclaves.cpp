class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]==1) q.push({i,0});
            if(board[i][m-1]==1) q.push({i,m-1});
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i]==1) q.push({0,i});
            if(board[n-1][i]==1) q.push({n-1,i});
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            board[r][c]=2;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]==1){
                    q.push({nr,nc});
                    board[nr][nc]=2;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1) ans++;
            }
        }
        return ans;
    }
};
