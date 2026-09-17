class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>distance(mat.begin(),mat.end());
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) q.push({i,j});
                else if(distance[i][j]==1)distance[i][j]=-1;
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr==mat.size() || nc==mat[0].size() || distance[nr][nc]!=-1){
                    continue;
                }
                distance[nr][nc]=1+distance[r][c];
                q.push({nr,nc});
            }
        }
        return distance;
    }
};
