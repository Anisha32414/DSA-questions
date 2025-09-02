class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
               arr[j]=arr[i];
               j++;
            }
        }
        
        arr.resize(j);
        if(arr[0]!=1 || arr.empty())
                return 1;
        for(int i=0;i<arr.size()-1;i++){
            
            if(arr[i+1]!=arr[i]+1 && arr[i+1]!=arr[i])
                 return arr[i]+1;
                 
                   
        }
        return arr.back()+1;
    }
};
