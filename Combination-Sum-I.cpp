#include<bits/stdc++.h>
using namespace std;

void combination_sum_I(int index,vector<int>&arr,int k,int &sum,vector<int>&dummy){
    if(sum>=k || index==arr.size()){
        if(sum==k){
            cout<<"[ ";
            for(auto ele:dummy){
                cout<<ele<<" ";
            }
            cout<<"]";
            cout<<endl;
        }
        return;
    }
    dummy.push_back(arr[index]);
    sum+=arr[index];
    combination_sum_I(index,arr,k,sum,dummy);

    dummy.pop_back();
    sum-=arr[index];
    combination_sum_I(index+1,arr,k,sum,dummy);
}

int main(){
    int n;
    cout<<"enter the number of elements:- ";
    cin>>n;
    vector<int>arr(n);
    int k;
    cout<<endl<<"enter the elements of the array :-"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl<<"enter the sum you are searching for :- ";
    cin>>k;
    vector<int>dummy;
    int sum=0;
    combination_sum_I(0,arr,k,sum,dummy);
    return 0;
}
