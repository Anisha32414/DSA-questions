class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        vector<char>dummy={'a','e','i','o','u','A','E','I','O','U'};
        while(i<=j){
            while(i<j && find(dummy.begin(),dummy.end(),s[i])==dummy.end()) i++;
            while(i<j && find(dummy.begin(),dummy.end(),s[j])==dummy.end()) j--;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
