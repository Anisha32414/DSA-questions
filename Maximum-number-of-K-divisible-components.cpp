class Solution {
public:
    vector<vector<int>>adj;
    int K;
    int ans=0;

    int components(int node,int parent,vector<int>&values){
        int sum=values[node];
        for(int next:adj[node]){
            if(next!=parent){
                sum+=components(next,node,values);
            }
        }
        if(sum%K==0)ans++;
        return sum%K;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k){
        adj.assign(n,{});
        K=k;
    
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        components(0,-1,values);
        return ans;
    }
};
