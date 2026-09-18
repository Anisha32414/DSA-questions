class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path,vector<int>&check){
        visited[node]=1;
        path[node]=1;
        check[node]=0;

        for(auto it:adj[node]){
            if(visited[it]==-1){
                if(dfs(it,adj,visited,path,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(path[it]==1){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int>visited(n,-1);
        vector<int>path(n,0);
        vector<int>res;
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i,adj,visited,path,check);
            }
        }
        for(int i=0;i<check.size();i++){
            if(check[i]==1) res.push_back(i);
        }
        return res;
    }
};
