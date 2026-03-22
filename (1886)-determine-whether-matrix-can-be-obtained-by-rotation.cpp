class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        vector<vector<int>>dummy(mat.size(),vector<int>(mat.size()));
        for(int i=0;i<3;i++){
            for(int a=0;a<mat.size();a++){
                for(int b=0;b<mat.size();b++){
                    dummy[b][mat.size()-1-a]=mat[a][b];
                }
            }
            mat=dummy;
            if(mat==target) return true;
        }
        return false;
    }
};
