#include<bits/stdc++.h>
using namespace std;
int max_subarray_sum_k(vector<int>&arr,int n,int k){
    int i=0;
    int j=0;
    int sum=0;
    int size=-1;
    while(j<n){
        sum+=arr[j];
        if(sum==k){
            size=max(size,j-i+1);
        }
        if(sum>k){
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return size;
}
int main(){
    int n;
    cout<<"enter no. of elements: ";
    cin>>n;
    vector<int>arr(n);
    int k;
    cout<<"enter element k: ";
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int len=max_subarray_sum_k(arr,n,k);
    cout<<"maximum subarray length with sum k :"<<len;
    return 0;
}
