#include<bits/stdc++.h>
using namespace std;

// space optimized
int mod=(int)(1e9+7);

int count_partitions_with_diff(vector<int>&arr,int target){
    int n=arr.size();
    vector<int>prev(target+1,0),curr(target+1,0);
    
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    
    if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int tar=0;tar<=target;tar++){
            int not_take=prev[tar];
            int take=0;
            if(arr[i]<=tar){
                take=prev[tar-arr[i]];
            }
            curr[tar]=(take + not_take)%mod;
        }
        prev=curr;
    }
    return curr[target];
}
int main(){
    int diff;
    cin>>diff;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ts=0;
    for(int it:arr) ts+=it;
    
    if(ts-diff<0 || (ts-diff)%2) cout<<"subsets NOT possible";
    else{
        int res=count_partitions_with_diff(arr,(ts-diff)/2);
        cout<<"no. of subsets with difference"<<diff<<" are : "<<res;
    }
    return 0;
}
