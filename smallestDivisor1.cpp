class Solution {
public:

    bool smallestDiv(vector<int>& nums,int mid ,int threshold){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=ceil((double)nums[i]/(double)mid);
        }
        return count<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left= 1;
        int right= *max_element(nums.begin(),nums.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            if(smallestDiv(nums,mid,threshold)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
