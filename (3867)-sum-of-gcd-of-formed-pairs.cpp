class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>max_ele(nums.size(),-1);
        max_ele[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            max_ele[i]=max(max_ele[i-1],nums[i]);
        }
        vector<int>prefix(nums.size());
        
        for(int i=0;i<nums.size();i++){
            prefix[i]=gcd(max_ele[i],nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        long long sum=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            sum+=gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
        return sum;
    }
};
