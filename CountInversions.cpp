class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int i=0,j=1,count=0;
        for(;i<n;){

            if(j==n){
                j=i+1;
                i++;
            }    
                
            if(i<j && arr[i]>arr[j]){
                count++;
            }
            j++;
        }
        return count;
    }
};
