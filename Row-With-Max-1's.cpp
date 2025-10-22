#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&rowIth , int m){
    int low=0;
    int high=m-1;
    int index=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(rowIth[mid]>=1){
            index=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return index;
}
pair<int,int> countOne(vector<vector<int>>& arr , int n , int m){
    int count_max=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        int count_1s=m-lower_bound(arr[i],m);
        if(count_1s > count_max){
            count_max=count_1s;
            ans=i;
        }
    }
    return {count_max,ans};
}
int main(){
    int n,m;
    cout<<"enter no. of rows : "<<endl;
    cin>>n;
    cout<<"enter no. of coloumn : "<<endl;
    cin>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"matrix is : "<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    pair<int,int>ans=countOne(arr,n,m);
    cout<<"max no. of one's are "<< ans.first <<" in  row : "<<ans.second;
    return 0;
}
