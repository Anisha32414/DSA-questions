#include <bits/stdc++.h>
using namespace std;
void topo_sort(int node,vector<vector<pair<int,int>>>&adj,stack<int>&st,vector<int>&vis){
    vis[node]=1;
    
    for(auto it:adj[node]){
        int v=it.first;
        if(vis[v]==-1){
            topo_sort(v,adj,st,vis);
        }
    }
    st.push(node);
}
vector<int> shortestDistance(int n,vector<vector<int>>&edges){
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        
        adj[u].push_back({v,wt});
    }
    
    vector<int>vis(n,-1);
    stack<int>st;
    
    for(int i=0;i<n;i++){
        if(vis[i]==-1){
            topo_sort(i,adj,st,vis);
        }
    }
    
    vector<int>dist(n,INT_MAX);
    dist[0]=0;
    
    while(!st.empty()){
        int v=st.top();
        st.pop();
        
        for(auto it:adj[v]){
            if(dist[v]+it.second<dist[it.first]){
                dist[it.first]=dist[v]+it.second;
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<int>>edges={{0,1,3},{1,2,2},{2,4,3},{1,3,1},{3,4,2},{4,5,4}};
    vector<int> shortest_distance=shortestDistance(6,edges);
    for(int i=0;i<shortest_distance.size();i++){
        cout<<"min distance to node "<<i<<" is "<<shortest_distance[i]<<endl;
    }
	return 0;

}
