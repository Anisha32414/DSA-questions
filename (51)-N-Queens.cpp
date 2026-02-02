class Solution {
public:
    bool queen_placed(int row,int col,vector<string>&board,int size){
        int dummy_row=row;
        int dummy_col=col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=dummy_row;
        col=dummy_col;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        row=dummy_row;
        col=dummy_col;
        while(row<size && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }

    void n_queen(vector<vector<string>>&result,vector<string>&board,int col,int size){
        if(col==size){
            result.push_back(board);
            return;
        }
        for(int row=0;row<size;row++){
            if(queen_placed(row,col,board,size)){
                board[row][col]='Q';
                n_queen(result,board,col+1,size);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n,string(n,'.'));
        n_queen(result,board,0,n);
        return result;
    }
};
