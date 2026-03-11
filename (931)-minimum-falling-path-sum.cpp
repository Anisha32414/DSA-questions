class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int>prev(matrix[0].begin(),matrix[0].end());
       
        for(int i=1;i<matrix.size();i++){
            vector<int>temp(matrix.size(),INT_MAX);
            
            for(int j=0;j<matrix.size();j++){
                int up=prev[j];
                int left=INT_MAX;
                int right=INT_MAX;
                if(j>0){
                    left=prev[j-1];
                }
                if(j<matrix.size()-1){
                    right=prev[j+1];
                }
                temp[j]=matrix[i][j]+min(up,min(left,right));
            }
            prev=temp;
        }
        return *min_element(prev.begin(),prev.end());
    }
};
