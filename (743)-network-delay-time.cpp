class Solution {
public:
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int n1=times[i][0];
            int n2=times[i][1];
            int wt=times[i][2];
            adj[n1].push_back({n2,wt});
        }
        vector<int> dist=dijkstra(adj,n+1,k);
        int res = *max_element(dist.begin()+1, dist.end());
        if(res==INT_MAX) return -1;
        return res;
    }
};
