class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1=0;
        long long s2=0;

        for(auto num:source) s1+=num;
        for(auto num:target) s2+=num;

        return s1==s2;
    }
};
