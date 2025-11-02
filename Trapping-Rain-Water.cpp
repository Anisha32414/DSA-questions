class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

        prefix[0]=height[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }

        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }

        int answer=0;
        for(int i=0;i<n;i++){
            if(height[i]<prefix[i] && height[i]<suffix[i]){
                answer+=min(prefix[i],suffix[i])-height[i];
            }
        }
        return answer;
    }
};
