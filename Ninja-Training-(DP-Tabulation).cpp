#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>mat[i][0];
        cin>>mat[i][1];
        cin>>mat[i][2];
    }

    vector<vector<int>>dp(n,vector<int>(4,0));

    dp[0][0]=max(mat[0][1],mat[0][2]);
    dp[0][1]=max(mat[0][0],mat[0][2]);
    dp[0][2]=max(mat[0][1],mat[0][0]);
    dp[0][3]=max(mat[0][1],max(mat[0][0],mat[0][2]));

    
    for(int i=1;i<n;i++){

        for(int last=0;last<4;last++){

            for(int term=0;term<3;term++){

                if(term!=last){
                    int point=mat[i][term]+dp[i-1][term];
                    dp[i][last]=max(dp[i][last],point);
                }
            }
        }
    }
    cout<<endl<<"maximum result possible is : "<<dp[n-1][3];
    return 0;
}
