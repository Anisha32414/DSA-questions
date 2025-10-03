#include<bits/stdc++.h>
using namespace std;
int floorSQRT(int n){
    int left=0;
    int right=n-1;
    int res=1;
    while(left<=right){
        int mid=left+(right-left)/2;
        long long i=mid*mid;
        if(i<=n){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return right;
}

int main(){
    int n;
    cout<<"enter the number whose sqrt you want to find";
    cin>>n;
    int ans=floorSQRT(n);
    cout<<ans;
    return 0;
}
