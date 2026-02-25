#include<bits/stdc++.h>
using namespace std;
int ninja(vector<vector<int>>&mat,int last,int index,vector<vector<int>>&dp){
    if(index==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,mat[0][i]);
            }
        }
        return maxi;
    }
    if(dp[index][last]!=-1) return dp[index][last];

    int max_ele=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int curr=mat[index][i]+ninja(mat,i,index-1,dp);
            max_ele=max(max_ele,curr);
        }
    }
    return dp[index][last]=max_ele;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>mat[i][0];
        cin>>mat[i][1];
        cin>>mat[i][2];
    }
    vector<vector<int>>dp(n,vector<int>(4,-1));
    int res=ninja(mat,3,n-1,dp);
    cout<<"max sum of training score: "<<res;
    return 0;
}
