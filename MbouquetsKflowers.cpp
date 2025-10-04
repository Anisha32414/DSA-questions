class Solution {
public:
 // m - no. of bouquets
 // k - no. of flowers
    bool countB(vector<int>& bloomDay,int mid,int m ,int k){
        int count=0;
        int nOfBouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                nOfBouquet+=(count/k);
                count=0;
            }
        }
        nOfBouquet+=(count/k);
        return nOfBouquet>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int val=1LL*m*1LL*k;
        if(val>bloomDay.size()) return -1;

        int left= *min_element(bloomDay.begin(),bloomDay.end());
        int right= *max_element(bloomDay.begin(),bloomDay.end());

        while(left<=right){
            int mid=left+(right-left)/2;
            if(countB(bloomDay,mid,m,k)){
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return left;
    }
};
