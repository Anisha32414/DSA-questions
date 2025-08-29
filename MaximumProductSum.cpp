class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n=arr.size(),j;
        int ltr=1;
        int rtl=1;
        int maxprod=INT_MIN;
        for (int i=0;i<n;i++){
            j=n-1-i;
            if(ltr==0)
               ltr=1;
            if(rtl==0)
               rtl=1;
            rtl*=arr[j];
            ltr*=arr[i];
            maxprod=max(maxprod,max(ltr,rtl));
        }
        return maxprod;
    }
};
