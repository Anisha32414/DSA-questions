#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<"nth term in fibonacci series: "<<fib(n,dp);
    return 0;
}
// 0 1 1 2 3 5 8 13...
