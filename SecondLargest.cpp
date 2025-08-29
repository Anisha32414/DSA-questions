class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int f,s;
        int n=arr.size();
        if(n<2)
        {
            return -1;
        }
        f=s=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>f)
            {
                s=f;
                f=arr[i];
            }
            else if(arr[i]>s && arr[i]!=f)
            {
                s=arr[i];
            }
        }
        if(s==INT_MIN)
             return -1;
        return s;
        
    }
};
