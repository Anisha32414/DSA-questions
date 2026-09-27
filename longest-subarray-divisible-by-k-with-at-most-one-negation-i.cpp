class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            vector<bool>seen(k,false);
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];

                int rem=((sum%k)+k)%k;
                if(rem==0) ans=max(ans,j-i+1);

                int val=(((2LL * nums[j])%k)+k)%k;
                seen[val]=true;

                if(seen[rem]){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
