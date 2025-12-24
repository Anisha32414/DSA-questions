class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int total_apple=0;
        for(int i=0;i<apple.size();i++){
            total_apple+=apple[i];
        }
        int cap=0;
        int box_req=0;
        for(int i=capacity.size()-1;i>=0;i--){
            if(cap>=total_apple) break;
            cap+=capacity[i];
            box_req++;
        }
        return box_req;
    }
};
