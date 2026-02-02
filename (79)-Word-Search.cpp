class Solution {
public:
    bool find_char(int index,int i,int j,string word,vector<vector<int>>&helper,vector<vector<char>>&board){
        if(index==word.size()-1){
            return true;
        }
        int direction[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
        
        for(auto d:direction){
            int ni=i+d[0];
            int nj=j+d[1];

            if(ni>=0 && nj>=0 && index+1 < word.size() &&
            ni<board.size() && nj<board[0].size() && 
            helper[ni][nj]==0 && word[index+1]==board[ni][nj]){

                helper[ni][nj]=1;
                if(find_char(index+1,ni,nj,word,helper,board))
                   return true;
                helper[ni][nj]=0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>helper(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){

                    helper[i][j]=1;
                    if(find_char(0,i,j,word,helper,board))
                       return true;
                    
                    helper[i][j]=0;
                }
            }
        }
        return false;
    }
};
