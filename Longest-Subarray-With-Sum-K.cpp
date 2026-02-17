#include<bits/stdc++.h>
using namespace std;
int max_subarray_sum_k(vector<int>&arr,int n,int k){
    unordered_map<int,int>mp;
    int prefix_sum=0;
    int size=0;
    for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
        if(prefix_sum==k){
            size=i+1;
        }
        if(mp.find(prefix_sum-k)!=mp.end()){
            size=max(size,i-mp[prefix_sum-k]);
        }
        if(mp.find(prefix_sum)==mp.end()){
            mp[prefix_sum]=i;
        }
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
