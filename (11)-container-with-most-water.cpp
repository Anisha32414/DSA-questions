class Solution {
public:
    int maxArea(vector<int>& height) {
        long long area=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            if(height[i]<=height[j]){
                area=max(area,1ll*height[i]*(j-i));
                i++;
            }
            else{
                area=max(area,1ll*height[j]*(j-i));
                j--;
            }
        }
        return int(area);
    }
};
