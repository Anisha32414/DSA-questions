#include <bits/stdc++.h>
using namespace std;
vector<int> shortest_path(vector<vector<pair<int,int>>> &adj,int sr,int ds){
    vector<int>ans;
    vector<int>parent(adj.size());
    
    for(int i=0;i<adj.size();i++){
        parent[i]=i;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(adj.size(),INT_MAX);
    dist[sr]=0;
    pq.push({0,sr});
    while(!pq.empty()){
        int d=pq.top().first;
        int n=pq.top().second;
        pq.pop();
        
        for(auto it:adj[n]){
            int node=it.first;
            int wt=it.second;
            if(dist[node]>d+wt){
                dist[node]=d+wt;
                parent[node]=n;
                pq.push({dist[node],node});
            }
        }
    }
    if(dist[ds]==INT_MAX) return {};
    
    int node=ds;
    while(parent[node]!=node){
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(sr);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
	vector<vector<pair<int,int>>> adj = {
        {{1,4}, {2,2}},
        {{0,4}, {3,1}},
        {{0,2}, {3,3}, {4,5}},
        {{1,1}, {2,3}, {4,3}},
        {{2,5}, {3,3}}
    };
    int sr,ds;
    sr=0;
    ds=4;
    vector<int> path=shortest_path(adj,sr,ds);
    for(int i=0;i<path.size();i++){
        cout<<path[i];
        if(i<path.size()-1)
        cout<<"->";
    }
	return 0;

}
