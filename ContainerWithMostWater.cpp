class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        long long prod=0;
        while(i<j){
            long long area=(j-i)*min(height[i],height[j]);
            prod=max(prod,area);
            if(height[i]<height[j]){
                i++;
            }
            else
                j--;
        }
        return prod;
    }
};
