#include<bits/stdc++.h>
using namespace std;
int max_sum(vector<int>&arr){
    int first=arr[0];
    int second=max(arr[0],arr[1]);

    for(int i=2;i<arr.size();i++){
        int curr=max(arr[i]+first,second);
        first=second;
        second=curr;
    }
    return second;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max sum of non adjacent elements: "<<max_sum(arr);
    return 0;
}
