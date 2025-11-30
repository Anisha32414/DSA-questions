class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();

        long total=0;
        for(int num:nums) total+=num;

        int target=total%p;
        if(target==0) return 0;

        unordered_map<int,int>mp;
        mp[0]=-1;

        int res=n;
        long prefix=0;
        for(int i=0;i<n;i++){
            prefix=(prefix+nums[i])%p;
            int need=(prefix - target + p) % p;

            if(mp.count(need)){
                res=min(res, i - mp[need]);
            }
            mp[(int)prefix]=i;
        }
        return res==n?-1:res;
    }
};
