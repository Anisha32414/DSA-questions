/*

class Solution {
public:
    int minimumCost(vector<int>& nums) {                                    ----> TC - O(n log n)
        int min1=INT_MAX;
        int min2=INT_MAX;
        int sum=nums[0];

        sort(nums.begin()+1,nums.end());
        min1=nums[1];
        min2=nums[2];

        sum+=(min1+min2);
        return sum;
    }
};

*/


class Solution {
public:
    int minimumCost(vector<int>& nums) {                                   // TC - O(n)
        int min1=100;
        int min2=100;
        int sum=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(min2>nums[i]){
                min2=nums[i];
            }
        }
        sum+=(min1+min2);
        return sum;
    }
};
