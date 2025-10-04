class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int count=0;
        int left= 1;
        int right= *max_element(nums.begin(),nums.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=0;
            for(int i=0;i<nums.size();i++){
                count+=ceil((double)nums[i]/(double)mid);
            }
            if(count<=threshold){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
