#include<bits/stdc++.h>
using namespace std;

bool booksAllocation(vector<int>&arr , int n , int mid ,int student){
    int stu=1;
    long long prevBook=0;

    for(int i=0;i<n;i++){
        if(arr[i]+prevBook<=mid){
            prevBook+=arr[i];
        }
        else{
            stu++;
            prevBook=arr[i];
        }
    }
    return stu<=student;
}

int main(){
    int n;
    int student;
    cout<<"enter the number of elements : "<<endl;
    cin>>n;
    cout<<endl<<"enter the number of students : "<<endl;
    cin>>student;

    if(student>n) {
        cout<<"books allocation not possible";
        return 0;
    }

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"our array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int left= *max_element(arr.begin(),arr.end());
    int right=0;

    for(int i=0;i<n;i++){
        right+=arr[i];
    }

    while(left<=right){
        int mid=left+(right-left)/2;
        if(booksAllocation(arr,n,mid,student)){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<"minimum of maximum pages in "<<n<<" no. of students is : "<<left;

    return 0;
}
