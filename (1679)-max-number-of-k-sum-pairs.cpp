class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int rem=k-nums[i];
            if(mp[nums[i]]>0 && mp[rem]>0){
                if(nums[i]==rem && mp[nums[i]]<2) continue;

                cnt++;
                mp[nums[i]]--;
                mp[rem]--;
            }
        }
        return cnt;
    }
};
