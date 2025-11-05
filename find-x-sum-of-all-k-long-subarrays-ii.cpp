class Solution {
public:

    long long getXsum(unordered_map<int,int>&mp,int x,long long windowSum){
        long long sum=0;
        if(mp.size()<x) return windowSum;

        priority_queue<pair<int,int>>pq;

        for(auto &p:mp){
            pq.push({p.second,p.first});
        }

        int count=0;
        while(!pq.empty() && count<x ){
            auto [freq,ele]=pq.top();
            pq.pop();
            sum+=(static_cast<long long>(freq) * static_cast<long long>(ele));
            count++;
        }
        return sum;
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long>answer;
        unordered_map<int,int>mp;

        int n=nums.size();

        long long windowSum=0;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            windowSum+=nums[i];
        }

        answer.push_back(getXsum(mp,x,windowSum));

        for(int i=k ; i<n ; i++){
            mp[nums[i-k]]--;
            windowSum-=nums[i-k];

            if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);

            mp[nums[i]]++;
            windowSum+=nums[i];

            answer.push_back(getXsum(mp,x,windowSum));
        }
        return answer;
    }
};
