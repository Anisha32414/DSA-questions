class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.size();
        string res="";
        string str="";

        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(str!=""){
                    st.push(str);
                    str="";
                }
            }
            else{ 
                str+=s[i];
            }
        }

        if(str!="") st.push(str);

        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()) res+=" ";
        }
        return res;
    }
};
