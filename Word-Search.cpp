class Solution {
public:
    bool helper(vector<vector<char>>& board, string &word,int ind,int n,int m,int r,int c){
        if(ind>=word.size()){
            return true;
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};

        for(vector<int>d : dir){
            int x=d[0];
            int y=d[1];

            int ni=x+r;
            int nj=y+c;
            if(ni>=0 && nj>=0 && ni<n && nj<m && word[ind]==board[ni][nj]){
                char temp=board[ni][nj];
                board[ni][nj]='#';

                if(helper(board,word,ind+1,n,m,ni,nj)) return true;

                board[ni][nj]=temp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char,int>mat_mp;
        unordered_map<char,int>word_mp;

        for(auto r:board){
            for(auto ch:r){
                mat_mp[ch]++;
            }
        }
        for(auto ch:word){
            word_mp[ch]++;
        }
        for(auto it:word_mp){
            if(mat_mp[it.first]<it.second) return false;
        }

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    char temp=board[i][j];
                    board[i][j]='#';
                    if(helper(board,word,1,n,m,i,j)) return true;
                    board[i][j]=temp;
                }
            }
        }
        return false;
    }
};
