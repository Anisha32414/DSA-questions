class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string res="";
        if(k==num.size()) return "0";

        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0') > (num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());

        int i=0;
        while(res.size()>i && res[i]=='0')i++;

        res=res.substr(i);
       
        return res.empty()?"0":res;
    }
};
