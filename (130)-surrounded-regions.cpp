class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[n-1][i]=='O') q.push({n-1,i});
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            board[r][c]='A';
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    board[nr][nc]='A';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='A') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
