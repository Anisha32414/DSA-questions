#include<bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
};
int fractional_knapsack(vector<item>&arr,int size,int w){
    int max_sum=0;
    sort(arr.begin(),arr.end(),[](item a,item b){
        int r1=(double)(a.value/a.weight);
        int r2=(double)(b.value/b.weight);
        return r1>r2;
    });

    for(int i=0;i<size && w>0 ;i++){
        if(arr[i].weight<=w){
            max_sum+=arr[i].value;
            w-=arr[i].weight;
        }
        else{
            max_sum+=w*((double)(arr[i].value/arr[i].weight));
            break;
        }
    }
    return max_sum;
}

int main(){
    int n;
    cout<<"enter no. of items : ";
    cin>>n;
    vector<item>arr(n);
    cout<<"enter the value and weight for each item "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].value>>arr[i].weight;
    }

    int w;
    cout<<endl<<"enter total weight of sack : ";
    cin>>w;
    cout<<endl;
    int res=fractional_knapsack(arr,n,w);
    cout<<"maximum value with weight can be : "<<res;
    return 0;
}
