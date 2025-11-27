class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int prefixSum=0;
        
        unordered_map<int,int>mp;
        mp[0]=1;

        for(int num:nums){
            prefixSum+=num;
            int mod=prefixSum % k;
            if(mod<0){
                mod=mod+k;
            }
            if(mp.find(mod)!=mp.end()){
                ans+=mp[mod];
                mp[mod]++;
            }
            else{
                mp[mod]=1;
            }
        }
        return ans;
    }
};
