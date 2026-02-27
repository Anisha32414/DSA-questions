class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=1;
                else{
                    int left=(j>0)?temp[j-1]:0;
                    int up=prev[j];
                    temp[j]=left + up;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
