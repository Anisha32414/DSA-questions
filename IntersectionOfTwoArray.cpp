class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> aux(nums1.begin(),nums1.end());
        unordered_set<int>result;

        for(int ele:nums2){
            if(aux.count(ele))
               result.insert(ele);           //no push_back in unorederd_set 
        }                                    //use insert()

        return vector<int>(result.begin(),result.end());
    }
};
