class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int i=0;
         
        int ind0=count(arr.begin(),arr.end(),0);
        int ind1=count(arr.begin(),arr.end(),1);
        int ind2=count(arr.begin(),arr.end(),2);
        
        for(;i<ind0;i++){
            arr[i]=0;
        }
        
        for(i=0;i<ind1;i++){
            arr[i+ind0]=1;
        }
        
        for(i=0;i<ind2;i++){
            arr[i+ind0+ind1]=2;
        }
        
    }
};
