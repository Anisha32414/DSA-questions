#include<bits/stdc++.h>
using namespace std;

void rat_in_maze(int i,int j,vector<vector<int>>matrix,vector<vector<int>>&choosen,int n,string term,vector<string>&result){
    if(i==n-1 && j==n-1){
        result.push_back(term);
        return;
    }

    int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
    char alph[4]={'D','L','R','U'};
    
    for(int k=0;k<4;k++){
        int ni=i+dir[k][0];
        int nj=j+dir[k][1];
      
        if(ni<n && nj<n && ni>=0 && nj>=0 && matrix[ni][nj]==1 && choosen[ni][nj]==0){
            choosen[ni][nj]=1;
            rat_in_maze(ni,nj,matrix,choosen,n,term+alph[k],result);
            choosen[ni][nj]=0;
        }
    }
}

int main(){
    int n=4;

    vector<vector<int>>matrix={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<int>>choosen(n,vector<int>(n,0));
    vector<string>result;
    if(matrix[0][0]==1){
        choosen[0][0]=1;
        rat_in_maze(0,0,matrix,choosen,n,"",result);
    }
    for(auto ele:result){
        cout<<ele<<" ";
    }
    return 0;
}

