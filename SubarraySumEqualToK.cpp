class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>aux;
        aux[0]=1;
        int cnt=0;
        int preSum=0;
        for(int ele:nums){
            preSum+=ele;
            if(aux.find(preSum-k)!=aux.end()){
                cnt+=aux[preSum-k];
            }
             aux[preSum]++;
        }
        return cnt;
    }
};
