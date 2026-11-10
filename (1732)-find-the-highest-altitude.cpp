class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN;
        int curr=0;
        ans=max(ans,curr);
        for(int i=0;i<gain.size();i++){
            curr+=gain[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};
