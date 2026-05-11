class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;

        vector<string>helper(numRows);

        int curr=0;
        bool goingdown=false;
        for(char ch:s){
            helper[curr]+=ch;
            if(curr==0 || curr==numRows-1){
                goingdown=!goingdown;
            }
            curr+=goingdown?1:-1;
        }

        string res="";
        for(string str:helper){
            res+=str;
        }
        return res;
    }
};
