#include <bits/stdc++.h>
using namespace std;

vector<int> topological_kahn(int n,vector<vector<int>>&adj){
    vector<int>res;
    queue<int>q;
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(int it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(int it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>>adj={{},{},{3},{1},{0,1},{0,2}};
    int n=adj.size();
    auto topo_sort=topological_kahn(n,adj);
    for(int it:topo_sort){
        cout<<it<<" ";
    }
    return 0;
}
