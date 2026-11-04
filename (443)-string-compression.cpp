class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        string str="";
        while(i<chars.size()){
            int cnt=0;
            char ch=chars[i];
            while(i<chars.size() && chars[i]==ch){
                i++;
                cnt++;
            }
            str+=ch;
            if(cnt>1){
                str+=(to_string(cnt));
            }
        }
        for(int i=0;i<str.size();i++){
            chars[i]=str[i];
        }
        return str.size();
    }
};
