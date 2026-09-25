#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>> &adj,int v,int s){
    set<pair<int,int>>st;
    vector<int>dist(v,INT_MAX);
    dist[s]=0;
    st.insert({0,s});
    while(!st.empty()){
        auto it=*st.begin();
        int node=it.second;
        int d=it.first;
        
        st.erase(it);
        for(auto it:adj[node]){
            int distance=it.second;
            int adjnode=it.first;
            
            if(distance+d<dist[adjnode]){
                if(dist[adjnode]!=INT_MAX){
                    st.erase({dist[adjnode],adjnode});
                }
                dist[adjnode]=distance+d;
                st.insert({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<pair<int,int>>> adj = {
        {{1,4}, {2,2}},
        {{0,4}, {3,1}},
        {{0,2}, {3,3}, {4,5}},
        {{1,1}, {2,3}, {4,3}},
        {{2,5}, {3,3}}
    };
    int v=adj.size();
    int s=0;
    vector<int> dist=dijkstra(adj,v,s);
    int i=0;
    for(int it:dist){
        cout<<"the shortest distance to node "<<i<<" is : "<<it<<endl;
        i++;
    }
    return 0;
}
