#include<bits/stdc++.h>
using namespace std;

void subset_sum(int index,vector<int>&arr,vector<int>&res,int &sum,int size){
    if(index==size){
        res.push_back(sum);
        return;
    }
    sum+=arr[index];
    subset_sum(index+1,arr,res,sum,size);
    sum-=arr[index];
    subset_sum(index+1,arr,res,sum,size);
}

int main(){
    int n;
    cout<<"enter number of elements :- ";
    cin>>n;
    vector<int>arr(n);
    cout<<endl<<"enter elements of array :-"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res;
    int sum=0;
    int index=0;
  
    subset_sum(index,arr,res,sum,n);
  
    sort(res.begin(),res.end());
    cout<<"sum of all subsets of entered array are :-"<<endl;
    for(int num:res){
        cout<<num<<" ";
    }
    return 0;
}
