class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res="";
        string aux=strs[0];
        if(strs.empty())return "";
        for(int i=1;i<n;i++){
            int j=0;
            while(j<aux.size() && j<strs[i].length() && aux[j]==strs[i][j]){
                j++;
            }
            aux=aux.substr(0,j);
            if(aux=="")return "";
        }
        return aux;
    }
};
