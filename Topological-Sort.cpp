#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> topological(int n,vector<vector<int>>&adj){
    vector<int>res;
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i,vis,st,adj);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main() {
    vector<vector<int>>adj={{},{},{3},{1},{0,1},{0,2}};
    int n=adj.size();
    auto topo_sort=topological(n,adj);
    for(int it:topo_sort){
        cout<<it<<" ";
    }
    return 0;
}
