class Solution {
public:
string minWindow(string str, string text) {
        
    if(text.size()>str.size()) return "";
    vector<int>freq(128,0);
    for(char c:text){
        freq[c]++;
    }
    int left=0;
    int right=0;
    int start=0;
    int ans_size=INT_MAX;
    int cnt=text.size();

    //ex : str="ADOBECODEBANC"
    //ex : text="ABC"   ---> "BANC"
    while(right<str.size()){
        if(freq[str[right]]>0){
            cnt--;
        }
        freq[str[right]]--;
        right++;

        while(cnt==0){
            if(right-left<ans_size){
                ans_size=(right-left);
                start=left;
            }
            freq[str[left]]++;
            if(freq[str[left]]>0){
                cnt++;
            }
            left++;
        }
    }
    return (ans_size==INT_MAX)?"":str.substr(start,ans_size);
    }
};
