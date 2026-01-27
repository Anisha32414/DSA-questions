#include<bits/stdc++.h>
using namespace std;

void subarray_with_sum_k(int index,int size,vector<int>&res,vector<int>&arr,int k,int sum){
    if(index>=size){
        if(sum==k){
            cout<<"{";
            for(auto ele:res){
                cout<<ele<<" ";
            }
            cout<<"}";
            cout<<endl;
        }
        return;
    }

    res.push_back(arr[index]);
    sum+=arr[index];
    subarray_with_sum_k(index+1,size,res,arr,k,sum);

    sum-=arr[index];
    res.pop_back();
    subarray_with_sum_k(index+1,size,res,arr,k,sum);
}

int main(){
    int n;
    int k;
    cout<<"enter number of elements :- ";
    cin>>n;
    cout<<endl<<"enter elements of array"<<endl;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>res;
    cout<<"enter the sum(k) you want to find :- ";
    cin>>k;

    subarray_with_sum_k(0,arr.size(),res,arr,k,0);
    return 0;
}
