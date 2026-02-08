class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>maxd,mind;
        int l=0;
        long long ans=0;
        
        for(int r=0;r<nums.size();r++){
            while(!maxd.empty() && nums[maxd.back()]<=nums[r]){
                maxd.pop_back();
            }
            maxd.push_back(r);

            while(!mind.empty() && nums[mind.back()]>=nums[r]){
                mind.pop_back();
            }
            mind.push_back(r);

            while((long long)(nums[maxd.front()]-nums[mind.front()])*(r-l+1) > k){
                if(maxd.front()==l) maxd.pop_front();
                if(mind.front()==l) mind.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
};
