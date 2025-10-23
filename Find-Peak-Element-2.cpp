class Solution {
public:

    int largestElementInd(vector<vector<int>>& mat,int mid , int n){
        int index=-1;
        int count_max=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>count_max){
                index=i;
                count_max=mat[i][mid];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int index=largestElementInd(mat,mid,row);
            int left=mid-1>=0?mat[index][mid-1]:-1;
            int right=mid+1<=high?mat[index][mid+1]:-1;
            if(mat[index][mid]>left && mat[index][mid]>right){
                return {index,mid};
            }
            else if(mat[index][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};
