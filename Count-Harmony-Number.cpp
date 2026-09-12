#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        long long odd_sum=0;
        long long even_sum=0;

        int new_var=0;
        for(int curr=0;curr<arr.size();curr++){
            if(i==curr) continue;
            if(new_var%2) even_sum+=arr[curr];
            else odd_sum+=arr[curr];
            new_var++;
        }
        if(even_sum==odd_sum)res++;
    }
    return res;
}
int main(){
    vector<int>arr={2,3,6,4,5,5};
    int res=func(arr);
    cout<<res;
    return 0;
}
