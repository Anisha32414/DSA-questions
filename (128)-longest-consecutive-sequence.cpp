class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp(nums.begin(),nums.end());
 
        if(mp.empty()) return 0;
        int cnt=1;

        for(int it:mp){
            if(mp.find(it-1)==mp.end()){
                int sum=1;
                int curr=it;
                while(mp.find(curr+1)!=mp.end()){
                    sum++;
                    curr++;
                }
                cnt=max(cnt,sum);
            }
        }
        return cnt;
    }
};
