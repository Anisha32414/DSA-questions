class Solution {
public:
    bool wordPattern(string pattern, string s) {

        istringstream ss(s);
        vector<string>aux;
        string str;

        while(ss >> str)
           aux.push_back(str);

        if(pattern.size()!=aux.size())
           return false;

        unordered_map<char,string>ctw;
        unordered_map<string,char>wtc;
        
        for(int i=0;i<pattern.size();i++){
            char c=pattern[i];
            string w=aux[i];

            if(ctw.count(c) && ctw[c]!=w)   return false;
            if(wtc.count(w) && wtc[w]!=c)   return false;

            ctw[c]=w;
            wtc[w]=c;
        }
        return true;
    }
};
