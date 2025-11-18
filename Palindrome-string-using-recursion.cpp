#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int l,int r){
    if(l>=r) return true;
    if(s[l]==s[r]){
        isPalindrome(s,l+1,r-1);
    }
    else{
        return false;
    }
    return true; 
}
int main(){
    string s="abcbd";                
    cout<<isPalindrome(s,0,s.size()-1);       //output - 0  (because s is not palindrome)
    return 0;
}
