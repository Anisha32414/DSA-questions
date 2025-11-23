class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int>mod1={0};
        vector<int>mod2={0};

        int sum=0;
        for(int x:nums){
            sum+=x;
            if(mod1.size()<3 && x%3==1) 
               mod1.push_back(x);
            if(mod2.size()<3 && x%3==2)
               mod2.push_back(x);
        }

        if(sum%3==0) return sum;

        int ele1=0;
        int res=0;
        for(auto y:mod1){
            ele1+=y;
            int ele2=0;
            for(auto z:mod2){
                ele2+=z;
                if((sum-ele1-ele2)%3==0){
                    res=max(res,sum-ele1-ele2);
                }
            }
        }
        return res;
    }
};
