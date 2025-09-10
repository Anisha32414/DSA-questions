class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int countElement= count(arr.begin(),arr.end(),target);
        return countElement;
    }
};
