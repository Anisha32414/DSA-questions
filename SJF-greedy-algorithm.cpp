#include<bits/stdc++.h>
using namespace std;

void waiting_time(vector<int>&process,int n,int &wait,int currTime,int i){
    if(i==n){
        return;
    }
    wait+=currTime;
    waiting_time(process,n,wait,currTime+process[i],i+1);
}

int main(){
    int n;
    cout<<"enter no. of processes";
    cin>>n;
    vector<int>process(n);
    cout<<"\n enter the process timings :"<<endl;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }
    
    sort(process.begin(),process.end());
    int wait=0;
    waiting_time(process,n,wait,0,0);
    cout<<"total waiting time for the given process : "<<wait;
    cout<<"\naverage waiting time : "<<wait/n;
    return 0;
}
