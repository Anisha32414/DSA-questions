class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        long long sc1 = 0;
        long long sc2 = 0;
        bool firstActive = true; 

        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] % 2 == 1) {
                firstActive = !firstActive;
            }

            if((i + 1) % 6 == 0) {
                firstActive = !firstActive;
            }

            if(firstActive)
                sc1 += nums[i];
            else
                sc2 += nums[i];
        }
        return sc1 - sc2;
    }
};
