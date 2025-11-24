class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3==0 && nums[i]%2==0){
                sum+=nums[i];
                cnt++;
            }
        }
        if(cnt==0) return 0;
        return sum/cnt;
    }
};
