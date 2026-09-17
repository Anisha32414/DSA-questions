class Solution {
public:
    bool dfs(int c,vector<vector<int>>&adj,vector<int>&visited){
        if(visited[c]==1) return false;
        if(visited[c]==2) return true;

        visited[c]=1;

        for(auto next:adj[c]){
            if(!dfs(next,adj,visited)){
                return false;
            }
        }
        visited[c]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>visited(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(!dfs(i,adj,visited)){
                return false;
            }
        }
        return true;
    }
};
