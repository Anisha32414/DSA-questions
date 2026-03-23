class Solution {
public:
    void product(vector<vector<int>>& grid, long long res, long long &ans,int col, int row, int i, int j) {
        if (i >= row || j >= col) return;

        res *= grid[i][j];

        if (i == row - 1 && j == col - 1) {
            ans = max(ans, res);
            return;
        }

        product(grid, res, ans, col, row, i + 1, j);

        product(grid, res, ans, col, row, i, j + 1);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;

        long long ans = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        product(grid, 1LL, ans, m, n, 0, 0);

        if (ans < 0) return -1;
        return ans % MOD;
    }
};
