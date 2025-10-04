class Solution {
public:

    bool maxCap(vector<int>& weights,int mid, int days){
        int day=1;
        int count=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+count>mid){
                day++;
                count=weights[i];
            }
            else{
                count+=weights[i];
            }
        }
        return day<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left= *max_element(weights.begin(),weights.end());
        int right=0;
        for(int i=0;i<weights.size();i++){
            right+=weights[i];
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            if(maxCap(weights,mid,days)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
