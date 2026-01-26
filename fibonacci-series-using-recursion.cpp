#include<bits/stdc++.h>           //write a recursive code to print the fibonacci-series upto given a range
using namespace std;

void f_series(int num,int i,int f,int s){
    if(i>=num) return;

    int res=f+s;
    cout<<" "<<res;
    f_series(num,i+1,s,res);

}
int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    
    if(n==1){
        cout<<0;
    }
    else if(n>=2){
        cout<<0;
        cout<<" "<<1;
    }

    int i=2;
    int f=0;
    int s=1;
    if(n>2) f_series(n,i,f,s);
    return 0;
}

//f-series -> 0 1 1 2 3 5 8 13 21 34...
