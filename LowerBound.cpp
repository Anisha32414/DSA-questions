#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr,int n,int x){
    int left=0;
    int right=arr.size()-1;
    int ans=n;
    
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]>=x){
            right=mid-1;
            ans=mid;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout<<"size of array";
    cin>>n;
    vector<int>arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int x;
    cout<<"value of x";
    cin>>x;
    
    int ans=lowerBound(arr,n,x);
    cout<<ans;
    return 0;
}
