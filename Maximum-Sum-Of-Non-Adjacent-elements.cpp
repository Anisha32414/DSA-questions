#include<bits/stdc++.h>
using namespace std;
int max_sum(vector<int>&arr){
    if(arr.size()==1){
        return arr[0];
    }
    vector<int>dp(arr.size(),0);
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<arr.size();i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }
    return dp[arr.size()-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max sum of non adjacent elements: "<<max_sum(arr);
    return 0;
}
