class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int answer=0;

        int leftMax=0;
        int rightMax=0;

        int left=0;
        int right=n-1;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=leftMax){
                    leftMax=height[left];
                }
                else{
                    answer+=leftMax-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rightMax){
                    rightMax=height[right];
                }
                else{
                    answer+=rightMax-height[right];
                }
                right--;
            }
        }
        return answer;
    }
};
