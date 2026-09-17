class Solution {
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<int>&visited){
        visited[city]=1;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]!=1 && isConnected[city][i]==1){
                dfs(i,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(),0);
        int provinces=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};
