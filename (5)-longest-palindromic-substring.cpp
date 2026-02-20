class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        
        for(int i=0;i<s.size();i++){
            int start=i;
            int end=i;
            while(start>=0 && end<s.size() && s[start]==s[end]){
                start--;
                end++;
            }

            string temp=s.substr(start+1 , end-start-1);
            if(res.size()<temp.size()){
                res=temp;
            }

            start=i;
            end=i+1;
            while(start>=0 && end<s.size() && s[start]==s[end]){
                start--;
                end++;
            }
            temp = s.substr(start+1,end-start-1);
            if(res.size()<temp.size()){
                res=temp;
            }
        }
        return res;
    }
};
