class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        long long total_cost=0;
        for(int i=0;i<s.size();i++){
            total_cost+=cost[i];
            mp[s[i]]+=cost[i];
        }
        long long max_sum=0;
        for(auto it:mp){
            max_sum=max(max_sum,it.second);
        }
        return total_cost-max_sum;
    }
};
