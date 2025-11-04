class Solution {
public:

    int getXsum(unordered_map<int,int>&mp,int x){

        int sum=0;
        
        if(mp.size()<x){
            for(auto &p:mp){
                sum+=(p.first * p.second);
            }
            return sum;
        }
        vector<pair<int,int>>freq;
        for(auto &p:mp) freq.push_back({p.second,p.first});

        sort(freq.rbegin(),freq.rend()); 

        for(int i=0;i<x && i<freq.size();i++){
            sum+=(freq[i].first * freq[i].second);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        vector<int>answer;
        int n=nums.size();
        unordered_map<int,int>mp;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }

        answer.push_back(getXsum(mp,x));
        for(int i=k;i<n;i++){
            mp[nums[i-k]]--;
            if( mp[nums[i-k]]==0) mp.erase(nums[i-k]);
            mp[nums[i]]++;
            answer.push_back(getXsum(mp,x));
        }
        return answer;
    }
};
