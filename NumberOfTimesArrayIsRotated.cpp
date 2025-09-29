#include <bits/stdc++.h>
using namespace std;
int timesArrayRotated(vector<int>arr,int n){
    int left=0;
    int right=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        
        if(arr[left]<=arr[right]){
            if(arr[left]<ans){
                index=left;
                ans=arr[left];
            }
        }
            
        if(arr[left]<=arr[mid]){
            if(arr[left]<ans){
                ans=arr[left];
                index=left;
            }
            left=mid+1;
        }
        
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
            }
            right=mid-1;
        }
    }
    return index;
}

int main() {
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans= timesArrayRotated(arr,n);
    cout<<"array rotated by : "<<endl;
    cout<<ans;
    return 0;
}
