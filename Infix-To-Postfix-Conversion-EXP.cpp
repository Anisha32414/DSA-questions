#include<bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch=='^')
       return 3;
    else if(ch=='*' || ch=='/')
       return 2;
    else if(ch=='+' || ch=='-')
       return 1;
    else 
       return -1;
}
string infix_to_Postfix(string s){
    string res="";
    stack<char>st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')){
            res=res+s[i];
        }
        else if(s[i]=='(' ){
            st.push(s[i]);
        }
        else if((!st.empty()) && s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res=res+st.top();
                st.pop();
            }
            if(!st.empty() && st.top()=='(')
                st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                res=res+st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res=res+st.top();
        st.pop();
    }
    return res;
}
int main(){
    string input;
    cout<<"enter the infix expression : "<<endl;
    cin>>input;
    string res=infix_to_Postfix(input);
    cout<<"infix to post expression of "<<input<<" is :"<<res;
    return 0;
}
