/* 
you are given a string s consisting of lowercase English words, each separated by a single space.
Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.
Return the resulting string.
*/


#include<bits/stdc++.h>
using namespace std;
string reverseString(string &s){
    int n=s.size();
    unordered_set<char>ch={'a','e','i','o','u'};
    int check=-1;
    for(int i=0;i<s.size();i++){
        int count=0;
        int start=i;
        while(i<n && s[i]!=' '){
            if(ch.find(s[i])!=ch.end()){
                count++;
            }
            i++;
        }
        if(count==check) reverse(s.begin()+start,s.begin()+i);
        if(check==-1) check=count;
        
    }
    return s;
}
int main(){
    string s="cat in book";            //example
    cout<<"input is : "<<s<<endl;
    cout<<"output is: "<<reverseString(s);
    return 0;
}
