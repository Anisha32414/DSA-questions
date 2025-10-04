class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left= *max_element(weights.begin(),weights.end());
        int right=0;
        for(int i=0;i<weights.size();i++){
            right+=weights[i];
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=0;
            int day=1;
            for(int i=0;i<weights.size();i++){
                if(weights[i]+count>mid){
                    day++;
                    count=weights[i];
                }
                else
                    count+=weights[i];
            }
            if(day<=days){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
