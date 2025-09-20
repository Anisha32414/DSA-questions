class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri;
        vector<int> rowI;
        for(int i=1;i<=numRows;i++){
            rowI=generateRows(i);
            pascalTri.push_back(rowI);
        }
        return pascalTri;
    }
    
    vector<int> generateRows(int rowNum){
        vector<int> row;
        int res=1;
        row.push_back(1);
        for(int i=1;i<rowNum;i++){
             res=res*(rowNum-i);
             res=res/i;
             row.push_back(res);
        }
        return row;
    }
};
