class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){        //sort in descending order
            return a.second>b.second;
        });

        string res="";
        for(auto it:v){
            while(it.second){
                res+=it.first;
                it.second--;
            }
        }
        return res;
    }
};
