#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int profit;
    int deadline;
};

int main(){
    int n;
    cout<<"enter the number of jobs:";
    cin>>n;
    job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
        cin>>arr[i].profit;
        cin>>arr[i].deadline;
    }
    
    sort(arr,arr+n,[](job a,job b){
        return a.profit>b.profit;
    });
    
    int max_deadline=0;
    for(int i=0;i<n;i++){
        max_deadline=max(max_deadline,arr[i].deadline);
    }
    
    vector<int>dummy(max_deadline+1,-1);
    int total_profit=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>=0;j--){
            if(dummy[j]==-1){
                dummy[j]=arr[i].id;
                total_profit+=arr[i].profit;
                cnt++;
                break;
            }
        }
    }
    cout<<"total maximized profit is :"<<total_profit<<endl;
    cout<<"no. of maximum jobs can be completed within deadline is : "<<cnt;
    
    return 0;
}
