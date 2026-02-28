class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res(2,-1);
       
        for(int n:nums){
            mp[n]++;
        }
        if(mp.size()<2) return res;
        vector<int>unique;
        for(auto p:mp){
            unique.push_back(p.first);
        }

        sort(unique.begin(),unique.end());
        
        for(int i=0;i<unique.size()-1;i++){
            for(int j=i+1;j<unique.size();j++){
                if(mp[unique[i]]!=mp[unique[j]]){
                    res[0]=unique[i];
                    res[1]=unique[j];
                    return res;
                }
            }
        }
        return res;
    }
};
