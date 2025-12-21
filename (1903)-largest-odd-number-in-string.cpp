class Solution {
public:
    string largestOddNumber(string num) {
        string res="";
        int i;
        for(i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0) break;
        }
        res=num.substr(0,i+1);
        return res;
    }
};
