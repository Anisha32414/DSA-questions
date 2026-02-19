//{1,8,6,2,5,4,8,3,7}--->49
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=INT_MIN;
    int i=0;
    int j=n-1;
    
    while(i<j){
        if(arr[i]>arr[j]){
            sum=max(sum,arr[j]*(j-i));
            j--;
        }
        else{
            sum=max(sum,arr[i]*(j-i));
            i++;
        }
    }
    cout<<sum;
    return 0;
}
