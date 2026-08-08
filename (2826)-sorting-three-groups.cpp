class Solution {
public:
    
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int dp[4]={0};
         for (int i = n - 1; i >= 0; i--) {
            for (int prev = 3; prev >= 0; prev--) {
                int ans = n + 1;
                if (nums[i] >= prev)
                    ans = min(ans, dp[nums[i]]);
                ans = min(ans, 1 + dp[prev]);
                dp[prev] = ans;
            }
        }
        return dp[0];
        
    }
};
