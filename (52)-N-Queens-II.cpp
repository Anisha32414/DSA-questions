class Solution {
public:
    bool is_Placed(int row,int col,int n,vector<string>&block){
        int dummy_row=row;
        int dummy_col=col;

        while(row>=0 && col>=0){
            if(block[row][col]=='Q')  return false;
            row--;
            col--;
        }
        row=dummy_row;
        col=dummy_col;

        while(col>=0){
            if(block[row][col]=='Q')  return false;
            col--;
        }
        row=dummy_row;
        col=dummy_col;

        while(row<n && col>=0){
            if(block[row][col]=='Q')  return false;
            row++;
            col--;
        }
        return true;
    }

    void count_nQueen(int n,int &res,vector<string>&block,int col){
        if(col==n){
            res++;
            return;
        }
        for(int row=0;row<n;row++){
            if(is_Placed(row,col,n,block)){
                block[row][col]='Q';
                count_nQueen(n,res,block,col+1);
                block[row][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int res=0;
        vector<string>block(n,string(n,'.'));
        count_nQueen(n,res,block,0);
        return res;
    }
};
