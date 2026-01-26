#include<bits/stdc++.h>           //write a recursive code to print the factorial of a number
using namespace std;

int fact(int num){
    if(num<=1) return 1;

    int res=num * fact(num-1);
    
    return res;
}

int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    cout<<"factorial of "<<n<<"is :- "<<fact(n);
    return 0;
}
