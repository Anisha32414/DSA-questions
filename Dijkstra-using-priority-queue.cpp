#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int v,vector<vector<pair<int,int>>>&adj,int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    vector<int>dist(v,INT_MAX);
    dist[s]=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        
        pq.pop();
        
        for(auto it:adj[node]){
            int n=it.first;
            int w=it.second;
            
            if(dist[n]>wt+w){
                dist[n]=wt+w;
                pq.push({dist[n],n});
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<pair<int,int>>>adj;
    adj={
    {{1,4}, {2,2}},
    {{0,4}, {3,1}},
    {{0,2}, {3,3}, {4,5}},
    {{1,1}, {2,3}, {4,3}},
    {{2,5}, {3,3}}
    };
    int v=adj.size();
    int s=0;
    vector<int> shortest_path=dijkstra(v,adj,s);
    int i=0;
    for(int it:shortest_path){
        cout<<"Shortest distance for node "<<i<<" is : "<<it<<endl;
        i++;
    }
    return 0;
}
