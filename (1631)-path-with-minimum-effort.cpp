class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0]=0;

        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()){
            auto [effort,x,y]=pq.top();
            pq.pop();

            if(effort>dist[x][y]) continue;

            if(x==rows-1 && y==cols-1) return effort;

            for(auto dir:directions){
                int nr=x+dir[0];
                int nc=y+dir[1];

                if(nr>=0 && nc>=0 && nr<rows && nc<cols){
                    int new_eff=max(effort,abs(heights[x][y]-heights[nr][nc]));
                    if(new_eff<dist[nr][nc]){
                        dist[nr][nc]=new_eff;
                        pq.push({new_eff,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};
