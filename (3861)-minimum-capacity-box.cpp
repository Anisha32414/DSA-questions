class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        vector<int>res(2,200);
        for(int i=0;i<capacity.size();i++){
            if(itemSize <=capacity[i]){
                if(res[0]>capacity[i]){
                    res[0]=capacity[i];
                    res[1]=i;
                }
                else if(res[0]==capacity[i]){
                    res[1]=min(res[1],i);
                }
            }
        }
        if(res[1]==200)return -1;
        return res[1];
    }
};
