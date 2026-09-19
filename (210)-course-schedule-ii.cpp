class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto it : prerequisites){
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
        }

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
        if(res.size() == n)
        return res;

        return {};
    }
};
