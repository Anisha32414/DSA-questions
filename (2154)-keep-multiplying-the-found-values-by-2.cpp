class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp.insert({nums[i],i});
        }
        while(1){
            if(mp.find(original)!=mp.end()){
                original=original*2;
            }
            else {
                break;
            }
        }
        return original;
    }
};
