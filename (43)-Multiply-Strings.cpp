class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";

        vector<int>helper(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                helper[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                helper[i+j]+=helper[i+j+1]/10;
                helper[i+j+1]%=10;
            }
        }
        string ans="";
        int i=0;
        while(helper[i]==0) i++;
        while(i<helper.size()){
            ans+=to_string(helper[i]);
            i++;
        }
        return ans;
    }
};
