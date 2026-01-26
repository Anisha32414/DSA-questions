#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string st,int start,int end){
    if(start>=end) return true;

    if(st[start]!=st[end]){
        return false;
    }
    return is_palindrome(st,start+1,end-1);
}

int main(){
    string str;
    cout<<"enter the string s:- "<<endl;
    cin>>str;
    if(is_palindrome(str,0,str.size()-1)){
        cout<<"the entered string "<<str<<" is plaindrome";
    }
    else{
        cout<<"the entered string "<<str<<" is not plaindrome";
    }
    return 0;
}
