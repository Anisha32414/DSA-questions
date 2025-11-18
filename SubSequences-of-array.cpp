#include<bits/stdc++.h>
using namespace std;
void subsequences(int i,vector<int>&arr,vector<int>&ans){
    if(i>=arr.size()){
        for(int num:ans) cout<<num<<" ";
        cout<<endl;
        if(ans.size()==0) cout<<"{}";
        return;
    }
    ans.push_back(arr[i]);
    subsequences(i+1,arr,ans);
    ans.pop_back();
    subsequences(i+1,arr,ans);   
}
int main(){
    vector<int>arr={3,2,5};
    vector<int>ans;
    subsequences(0,arr,ans);
    return 0;
}
