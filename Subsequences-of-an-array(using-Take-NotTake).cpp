#include<bits/stdc++.h>
using namespace std;

void subarray(vector<int>&arr,int index,int size,vector<int>&res){
    if(index>=size){
        cout<<"{";
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<"}";
        cout<<endl;
        return;
    }
    res.push_back(arr[index]);
    subarray(arr,index+1,size,res);
    res.pop_back();
    subarray(arr,index+1,size,res);
}

int main(){
    int n;
    cout<<"enter no. of elements in array:- ";
    cin>>n;
    vector<int>arr(n);
    cout<<endl<<"enter elements :- "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res;    
    subarray(arr,0,arr.size(),res);
    return 0;
}
