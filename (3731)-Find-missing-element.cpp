class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;

        int min_ele=INT_MAX;
        int max_ele=INT_MIN;
        for(int i=0;i<nums.size();i++){
            min_ele=min(min_ele,nums[i]);
            max_ele=max(max_ele,nums[i]);
            mp[nums[i]]=nums[i];
        }
        
        for(int i=min_ele;i<max_ele;i++){
            if(mp.find(i)==mp.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};
