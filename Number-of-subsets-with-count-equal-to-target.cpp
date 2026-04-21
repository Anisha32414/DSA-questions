#include<bits/stdc++.h>
using namespace std;
int count_target_k_in_array(vector<int>&arr,int n,int k){
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=k) dp[0][arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int tar=1;tar<=k;tar++){
            int not_take=dp[i-1][tar];
            int take=0;
            if(arr[i]<=tar){
                take=dp[i-1][tar-arr[i]];
            }
            dp[i][tar]=take + not_take;
        }
    }
    return dp[n-1][k];
}
int main(){
    int k;
    cin>>k;
    int ele;
    cin>>ele;
    vector<int>arr(ele);
    for(int i=0;i<ele;i++){
        cin>>arr[i];
    }
    int res=count_target_k_in_array(arr,ele,k);
    cout<<res;      
    return 0;
}
