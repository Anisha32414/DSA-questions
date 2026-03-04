class Solution {
public:
    bool is_valid(int i,int j,int row,int col,vector<vector<int>>& mat){
        int cnt1=0;
        for(int a=0;a<col;a++){
            if(mat[i][a]==1){
                cnt1++;
            }
            if(cnt1>1){
                return false;
            }
        }

        cnt1=0;
        for(int a=0;a<row;a++){
            if(mat[a][j]==1){
                cnt1++;
            }
            if(cnt1>1){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1 && is_valid(i,j,row,col,mat)){
                    res++;
                }
            }
        }
        return res;
    }
};
