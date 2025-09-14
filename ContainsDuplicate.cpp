class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>aux;
        for(int ele:nums){
            if(aux.count(ele))
                return true;
            aux.insert(ele);
        }
        return false;
    }
};
