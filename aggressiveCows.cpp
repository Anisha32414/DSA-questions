#include <bits/stdc++.h>
using namespace std;

bool aggresiveCows(vector<int>&arr,int n,int mid,int cow){
    int cowPrev=arr[0];
    int countCow=1;
  
    for(int i=1;i<n;i++){
        if(arr[i]-cowPrev>=mid){
            countCow++;
            cowPrev=arr[i];
        }
    }
    return countCow>=cow;
}

int main(){
    int n;
    int cow;
    cout<<"enter the number of cows";
    cin>>cow;
    cout<<"enter the size of array";
    cin>>n;
    vector<int>arr(n);
  
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array is: ";
  
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  
    cout<<endl;
    sort(arr.begin(),arr.end());
    int left=1;
    int right=arr[n-1];
  
    while(left<=right){
        int mid=left+(right-left)/2;
        if(aggresiveCows(arr,n,mid,cow)){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<"maximum of minimum distance b/w cows : "<<right;
    return 0;
}
