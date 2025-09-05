class Solution {
  public:
    int minChar(string &s) {
        // code here
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+'$'+rev;
        int m=temp.size();
        vector<int>arr(m,0);
        
        for(int i=1;i<m;i++){
            int j=arr[i-1];
            while(j>0 && temp[i]!=temp[j]){
                j=arr[j-1];
            }
            if(temp[i]==temp[j])
                j++;
            arr[i]=j;
        }
        return n-arr[m-1];
    }
};
    
