class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        
        long long val = 1;
        row[0] = 1;

        for (int k = 1; k <= rowIndex; k++) {
            val = val * (rowIndex - k + 1) / k;
            row[k] = val;
        }

        return row;
    }
};
