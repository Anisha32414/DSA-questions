class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return -1;
        long long submission=0;
        long long product=1;
        int i;
        int j;
        vector<long long>suffixProduct(n+1,1);
        for(int i=n-1;i>=0;i--){
            if(suffixProduct[i+1] > 1e18 / nums[i])
                suffixProduct[i] = 1e18;
            else
                suffixProduct[i] = suffixProduct[i+1] * nums[i];
        }
        
        for(i=0;i<n;i++){
            product=suffixProduct[i+1];
            
            if(submission==product) return i;
            submission+=nums[i];
        }
        
        return -1;
    }
};
