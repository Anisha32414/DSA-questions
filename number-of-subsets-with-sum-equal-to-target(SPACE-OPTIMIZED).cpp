#include<bits/stdc++.h>
using namespace std;

// space optimized

int count_target_k_in_array(vector<int>&arr,int n,int k){
    vector<int>prev(k+1,0),curr(k+1,0);

    prev[0]=1;
    if(arr[0]<=k) prev[arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int tar=0;tar<=k;tar++){
            int not_take=prev[tar];
            int take=0;
            if(arr[i]<=tar){
                take=prev[tar-arr[i]];
            }
            curr[tar]=take + not_take;
        }
        prev=curr;
    }
    return curr[k];
}
int main(){
    int k;
    cin>>k;
    int ele;
    cin>>ele;
    vector<int>arr(ele);
    for(int i=0;i<ele;i++){
        cin>>arr[i];
    }
    int res=count_target_k_in_array(arr,ele,k);
    cout<<res;      
    return 0;
}
