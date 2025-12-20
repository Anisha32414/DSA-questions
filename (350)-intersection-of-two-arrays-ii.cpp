class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>dummy=nums2;
    
        for(int i=0;i<nums1.size();i++){
            auto num=find(dummy.begin(),dummy.end(),nums1[i]);
            if(num!=dummy.end()){
                ans.push_back(nums1[i]);
                dummy.erase(num);
            }
        }
        return ans;
    }
};
