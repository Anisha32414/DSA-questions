class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int n:nums1) freq[n]++;
        for(int n:nums2) freq[n]--;

        int cost=0;
        for(auto it:freq){
            if(it.second%2) return -1;
            cost+=abs(it.second);
        }
        return cost/4;
    }
};
