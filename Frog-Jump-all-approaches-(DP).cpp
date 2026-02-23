/*
1. DP:-Memoization
TC - O(n)
SC - O(n)+O(n) ---> stack space


#include<bits/stdc++.h>
using namespace std;
int frog_jump(vector<int>&arr,vector<int>&dp,int n){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int l=frog_jump(arr,dp,n-1)+abs(arr[n]-arr[n-1]);

    int r=INT_MAX;
    if(n>1){
        r=frog_jump(arr,dp,n-2)+abs(arr[n]-arr[n-2]);
    }
    return dp[n]=min(l,r);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n,-1);
    int energy=frog_jump(arr,dp,n-1);
    cout<<"min energy required by the frog to reach at last : "<<energy;
    return 0;
}



2. DP - Tabulation
TC - O(n)
SC - O(n)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int l=dp[i-1]+abs(arr[i]-arr[i-1]);
        int r=INT_MAX;
        if(i>1){
            r=dp[i-2]+abs(arr[i]-arr[i-2]);
        }
        dp[i]=min(l,r);
    }
    cout<<"min energy required: "<<dp[n-1];
    return 0;
}

*/

// 3. Space optimization ---> SC - O(1) , TC - O(n)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int first=0;
    int second=abs(arr[0]-arr[1]);
    for(int i=2;i<n;i++){
        int l=abs(arr[i]-arr[i-1])+second;
        int r=abs(arr[i]-arr[i-2])+first;
        int curr=min(l,r);

        first=second;
        second=curr;
    }
    cout<<"min energy is :"<<second;
    return 0;
}
