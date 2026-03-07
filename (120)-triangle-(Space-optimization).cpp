class Solution {           // space optimized solution
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n, 0);

        for (int i = 0; i < n; i++)
            next[i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            vector<int>dummy(n,0);
            for (int j=i;j>=0;j--){
                int down=triangle[i][j]+next[j];
                int diag=triangle[i][j]+next[j+1];
                dummy[j]=min(down,diag);
            }
            next=dummy;
        }
        return next[0];
    }
};
