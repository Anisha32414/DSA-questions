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
    vector<int>prev(4);

    prev[0]=max(mat[0][1],mat[0][2]);
    prev[1]=max(mat[0][0],mat[0][2]);
    prev[2]=max(mat[0][0],mat[0][1]);
    prev[3]=max(mat[0][2],max(mat[0][0],mat[0][1]));

    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int term=0;term<3;term++){
                if(last!=term){
                    temp[last]=max(temp[last],mat[day][term]+prev[term]);
                }
            }
        }
        prev=temp;
    }
    cout<<endl<<"max res is : "<<prev[3];
    return 0;
}
