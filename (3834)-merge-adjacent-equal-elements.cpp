class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>merge;
        for(auto n:nums){
            long long curr=n;
            while(!merge.empty() && merge.back()==curr){
                curr+=merge.back();
                merge.pop_back();
            }
            merge.push_back(curr);
        }
        return merge;
    }
};
