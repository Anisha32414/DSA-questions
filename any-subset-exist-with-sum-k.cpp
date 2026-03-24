#include<bits/stdc++.h>
using namespace std;
bool subset_sum_k(vector<int>&arr,int target,int index){
    if(target==0) return true;
    if(index==0) return (target==arr[index]);

    bool not_take=subset_sum_k(arr,target,index-1);
    bool take=false;
    if(target>=arr[index]){
        take=subset_sum_k(arr,target-arr[index],index-1);
    }
    return (take or not_take);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<"subset exist with sum k? "<<subset_sum_k(arr,k,n-1);
    //check wether a subset exist or not in the given array with sum equal to k
    return 0;
}
