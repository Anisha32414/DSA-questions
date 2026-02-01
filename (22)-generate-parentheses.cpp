class Solution {
public:
    void resultant_vector(vector<string>&result, string &str,int n,int open ,int close){
        if(str.size()==n*2){
            result.push_back(str);
            return;
        }

        if(open<n){
            str+='(';
            resultant_vector(result,str,n,open+1,close);
            str.pop_back();
        }

        if(close<open){
            str+=')';
            resultant_vector(result,str,n,open,close+1);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string str="";
        resultant_vector(result,str,n,0,0);
        return result;
    }
};
