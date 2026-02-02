class Solution {
public:
    void all_combinations(vector<vector<int>>&answer,vector<int>&term,int n,int k,int index){
        if(k==0){
            answer.push_back(term);
            return;
        }
        for(int i=index;i<=n;i++){
            term.push_back(i);
            all_combinations(answer,term,n,k-1,i+1);
            term.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>answer;
        vector<int>term;
        all_combinations(answer,term,n,k,1);
        return answer;
    }
};
