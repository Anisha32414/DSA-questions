class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int un_sorted=0;
        int m=strs[0].size();
        int n=strs.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                if(strs[j][i]>strs[j+1][i]){
                    un_sorted++;
                    break;
                }
            }
        }
        return un_sorted;
    }
};
