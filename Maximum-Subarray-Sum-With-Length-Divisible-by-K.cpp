class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long>minPrefixSum(k,LLONG_MAX);

        long long result=LLONG_MIN;
        long long prefix=0;
        int n=nums.size();

        minPrefixSum[0]=0;

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int mod=(i+1)%k;
            
            if(minPrefixSum[mod]!=LLONG_MAX){
                result=max(result,prefix-minPrefixSum[mod]);
            }
            minPrefixSum[mod]=min(minPrefixSum[mod],prefix);
        }
        return result;
    }
};
