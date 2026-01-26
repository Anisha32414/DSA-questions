//reversing array using recursion

#include<bits/stdc++.h>
using namespace std;

void reverse_arr(vector<int>&arr,int start,int end){
    if(start>=end) return;

    swap(arr[start],arr[end]);
    reverse_arr(arr,start+1,end-1);
}

int main(){
    int n;
    cout<<"enter no. of elements";
    cin>>n;
    vector<int>arr(n);
    cout<<endl<<"enter the elements of the vector: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl<<"entered vector by the user is :- "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    reverse_arr(arr,0,arr.size()-1);
    cout<<endl<<"array after reversing :-"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
