class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),[&](auto &x,auto &y){
            if(x[1]==y[1]) return x[0]>y[0];
            return x[1]<y[1];
        });

        int ans=0;
        int a=-1;
        int b=-1;

        for(auto interval:intervals){
            int l=interval[0];
            int r=interval[1];

            if(l>b){
                ans+=2;
                a=r-1;
                b=r;
            }
            else if(l>a){
                ans+=1;
                a=b;
                b=r;
            }
        }
        return ans;
    }
};
