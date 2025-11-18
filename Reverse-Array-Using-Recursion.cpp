#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr,int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    reverseArray(arr,l+1,r-1);
}
int main(){
    int n;
    cout<<"n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl<<"array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    reverseArray(arr,0,n-1);
    cout<<endl<<"array after reversing : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
