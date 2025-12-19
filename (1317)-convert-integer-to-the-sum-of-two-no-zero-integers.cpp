class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int>res;
        for(int i=1;i<n;i++){
            int a=i;
            int b=n-i;
            if(!contain_zero(a) && !contain_zero(b)){
                res.push_back(a);
                res.push_back(b);
                break;
            }
        }
        return res;
    }
    bool contain_zero(int num){
        string str=to_string(num);
        if(str.find('0')!=string::npos) return true;
        return false;
    }
};
