#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path){
    visited[node]=1;
    path[node]=1;

    for(auto it:adj[node]){
        if(visited[it]==-1){
            if(dfs(it,adj,visited,path)==true){
                return true;
            }
        }
        else if(path[it]==1){
            return true;
        }
    }
    path[node]=0;
    return false;
}
bool directed_cycle(int n,vector<vector<int>>&adj){
    vector<int>visited(n+1,-1);
    vector<int>path(n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==-1){
            if(dfs(i,adj,visited,path)==true){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool res=directed_cycle(n,adj);
    cout<<"cycle present in directed graph? "<<res;
    return 0;
}
