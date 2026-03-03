class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1="qwertyuiop",r2="asdfghjkl",r3="zxcvbnm";
        vector<string>ans;
        for(string s:words){
            string d=s,r;
            transform(d.begin(), d.end(), d.begin(), ::tolower);
            if(r1.find(d[0])!=string::npos){
                r=r1;
            }
            else if(r2.find(d[0])!=string::npos){
                r=r2;
            }
            else r=r3;
            bool t=1;
            for(char c:d){
                if(r.find(c)==string::npos){
                    t=0;
                    break;
                }
            }
            if(t)ans.push_back(s);
        }
        return ans;
    }
};
