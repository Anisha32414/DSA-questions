class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();

        if(m<3 || n<3) return 0;

        priority_queue<vector<int>,
                       vector<vector<int>>,
                       greater<vector<int>>
        >pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});

            visited[i][0]=true;
            visited[i][n-1]=true;
        }

        for(int i=0;i<n;i++){
            if(!visited[0][i]){
                visited[0][i]=true;
                pq.push({heightMap[0][i],0,i});
            }
            if(!visited[m-1][i]){
                visited[m-1][i]=true;
                pq.push({heightMap[m-1][i],m-1,i});
            }
        }

        vector<int>dr={0,1,0,-1};
        vector<int>dc={-1,0,1,0};

        int water=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int height=curr[0];
            int row=curr[1];
            int col=curr[2];

            for(int k=0;k<4;k++){
                int new_row=row+dc[k];
                int new_col=col+dr[k];
                
                if(new_row>=0 && new_row<m && 
                new_col>=0 && new_col<n && 
                visited[new_row][new_col]==false){

                    visited[new_row][new_col]=true;

                    if(heightMap[new_row][new_col]<height){
                        water+=(height-heightMap[new_row][new_col]);
                    }

                    pq.push({max(height,heightMap[new_row][new_col]),new_row,new_col});
                }
            }
        }
        return water;
    }
};
