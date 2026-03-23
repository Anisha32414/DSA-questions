class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;
 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>>minprod(n,vector<long long>(m));
        vector<vector<long long>>maxprod(n,vector<long long>(m));

        minprod[0][0]=maxprod[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            minprod[i][0]=maxprod[i][0]=minprod[i-1][0]*grid[i][0];
        }
        for(int j=1;j<m;j++){
            minprod[0][j]=maxprod[0][j]=minprod[0][j-1]*grid[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long val=grid[i][j];

                long long a=minprod[i-1][j]*val;
                long long b=maxprod[i-1][j]*val;
                long long c=minprod[i][j-1]*val;
                long long d=maxprod[i][j-1]*val;

                minprod[i][j]=min({a,b,c,d});
                maxprod[i][j]=max({a,b,c,d});
            }
        }
        long long ans=maxprod[n-1][m-1];
        if (ans < 0) return -1;
        return ans % MOD;
    }
};
