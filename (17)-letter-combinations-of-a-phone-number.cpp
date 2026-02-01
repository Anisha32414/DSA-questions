class Solution {
public:
    void telephone(vector<string>&res,string &curr,vector<string>mp,string digits,int index){
        if(digits.size()==curr.size()){
            res.push_back(curr);
            return;
        }

        string str=mp[digits[index]-'0'];

        for(char ch:str){
            curr.push_back(ch);
            telephone(res,curr,mp,digits,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string curr="";
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        telephone(res,curr,mp,digits,0);
        return res;
    }
};
