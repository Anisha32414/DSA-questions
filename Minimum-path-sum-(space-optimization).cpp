class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<int>prev(c,0);

        for(int i=0;i<r;i++){
            vector<int>temp(c,0);
            for(int j=0;j<c;j++){

                if(i==0 && j==0) temp[j]=grid[i][j];
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=temp[j-1];
                    }
                    temp[j]=grid[i][j]+min(up,left);
                }
            }
            prev=temp;
        }
        return prev[c-1];
    }
};
