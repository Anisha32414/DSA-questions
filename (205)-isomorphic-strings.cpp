class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>mpS;
        unordered_map<char,int>mpT;
        
        for(int i=0;i<s.size();i++){
            if(mpS.find(s[i])==mpS.end()){
                mpS[s[i]]=i;
            }
            if(mpT.find(t[i])==mpT.end()){
                mpT[t[i]]=i;
            }
            if(mpS[s[i]]!=mpT[t[i]]){
                return false;
            }
        }
        return true;
    }
};
