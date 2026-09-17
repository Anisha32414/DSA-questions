class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto course:prerequisites){
            int c=course[0];
            int p=course[1];

            adj[p].push_back(c);
            indegree[c]++;
        }

        queue<int>q;
        for(int it=0;it<indegree.size();it++){
            if(indegree[it]==0){
                q.push(it);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(int next:adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return cnt==numCourses;
    }
};
