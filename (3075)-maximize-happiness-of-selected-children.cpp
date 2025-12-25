class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int count=0;
        long long sum=0;
        for(int i=happiness.size()-1;i>=0;i--){
            if(k==count) break;
            int ele=happiness[i]-count;
            if(ele>=0){
                sum+=ele;
                count++;
            }
        }
        return sum;
    }
};
