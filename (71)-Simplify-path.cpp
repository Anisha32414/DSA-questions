class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string ans="";
        int i=0;
        int n=path.size();
        string curr="";

        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            curr="";
            while(i<n && path[i]!='/'){
                curr+=path[i];
                i++;
            }

            if(curr=="."){
                continue;
            }
            if(curr==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(curr);
            }
        }
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans=="")return "/";
        return ans;
    }
};
