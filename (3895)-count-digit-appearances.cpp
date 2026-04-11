class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        string str="";
        for(int it:nums){
            string curr=to_string(it);
            str+=curr;
        }
        char s=digit+'0';
        int res=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==s) res++;
        }
        return res;
    }
};
