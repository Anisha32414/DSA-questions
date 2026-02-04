class Solution {
public:
    bool is_palindrome(int start,int end,string s){
        while(end>=start){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void palindrome_partition(vector<vector<string>>&res,vector<string>&path,string s,int index){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(is_palindrome(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                palindrome_partition(res,path,s,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        palindrome_partition(res,path,s,0);
        return res;
    }
};
