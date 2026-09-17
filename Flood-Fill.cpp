class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc, int color) {
        vector<vector<int>>image(images.begin(),images.end());
        int curr=image[sr][sc];
        if(curr==color) return image;
        image[sr][sc]=color;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<image.size() && nc<image[0].size() && image[nr][nc]==curr){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};
