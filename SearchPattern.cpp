class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int>res;
        int t=txt.size();
        int p=pat.size();
        for (int i=0;i<=t-p;i++){
            if(txt.substr(i,p)==pat)
               res.push_back(i);
        }
        return res;
    }
};
