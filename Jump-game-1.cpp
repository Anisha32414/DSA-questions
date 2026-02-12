#include<bits/stdc++.h>
using namespace std;

void jump1(vector<int>&arr,int size,int i,int &res,int &max_ind){
    if(i>=size){
        res=1;
        return;
    }
    if(max_ind<i){
        return;
    }
    max_ind=max(max_ind,i+arr[i]);
    jump1(arr,size,i+1,res,max_ind);
}

int main(){
    int n;
    cout<<"enter no. of processes";
    cin>>n;
    vector<int>arr(n);
    cout<<"\n enter the process timings :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=0;
    int max_ind=0;
    jump1(arr,n,0,res,max_ind);
    cout<<"reached at last index ?";
    cout<<(res==1?"Yes":"No");
    return 0;
}
