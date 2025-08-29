class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxsum=0;
        int minsum=0;
        int maxres=arr[0],minres=arr[0];
        int totalSum=0,normalSum,circularSum;
        for(int i=0;i<n;i++){
            
            maxsum=max(maxsum+arr[i],arr[i]);
            maxres=max(maxres,maxsum);
           
            minsum=min(minsum+arr[i],arr[i]);
            minres=min(minres,minsum);
            
            totalSum+=arr[i];
        }
        circularSum=totalSum-minres;
        normalSum=maxres;
        if(totalSum==minres)
           return normalSum;
        return max(normalSum,circularSum);
    }
};
