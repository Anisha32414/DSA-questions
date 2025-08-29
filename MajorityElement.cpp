class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int ele1=INT_MIN,ele2=INT_MIN,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(ele1==arr[i])
                 c1++;
            else if(ele2==arr[i])
                 c2++;
            else if(c1==0){
                ele1=arr[i];
                c1++;
            }
            else if(c2==0){
                ele2=arr[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int>res;
        c1=0;
        c2=0;
        for(int i=0;i<n;i++){
            if(ele1==arr[i])
                c1++;
            else if(ele2==arr[i])
                c2++;
        }
        if(c1>floor(n/3))
                res.push_back(ele1);
        if(c2>floor(n/3))
                res.push_back(ele2);
                
        
        if(res.size()==2 && ele1>ele2){
            reverse(res.begin(),res.end());
        }
        return res;
    }
};
