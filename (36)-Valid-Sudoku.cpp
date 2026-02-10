class Solution {
public:
    bool is_valid(char ch,int row,int col,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch && i!=row) return false;

            if(board[row][i]==ch && i!=col) return false;

            int r=3*(row/3)+i/3;
            int c=3*(col/3)+i%3;
            if(board[r][c]==ch && (r!=row || c!=col)) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!is_valid(board[i][j],i,j,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
