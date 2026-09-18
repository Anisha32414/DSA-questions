class Solution {
public:
    bool bfs(int start,int v,vector<vector<int>>&graph,vector<int>&clr){
        queue<int>q;
        q.push(start);
        clr[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:graph[node]){
                if(clr[it]==-1){
                    clr[it]=!clr[node];
                    q.push(it);
                }
                else if(clr[it]==clr[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>clr(v,-1);
        for(int i=0;i<v;i++){
            if(clr[i]==-1){
                if(bfs(i,v,graph,clr)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
