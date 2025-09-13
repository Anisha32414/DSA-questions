class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        vector<int>aux(n+1,0);
        
        for(int i=0;i<n;i++){
            if(citations[i]>=n)
                aux[n]++;
            else
                aux[citations[i]]++;
        }
        
        int count=0;
        
        for(int i=n;i>=0;i--){
            count+=aux[i];
            if(count>=i)
                return i;
        }
        return 0;
    }
};
