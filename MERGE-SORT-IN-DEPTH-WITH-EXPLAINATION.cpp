/*

In merge sort:

The left subtree of the recursion tree is solved first. After completely sorting the left half,
we then move to the right half of the array.

While solving a merge sort problem diagrammatically, we break the complete array into single
elements that cannot be divided further.
→ This is done to ease understanding.

However, in actual execution, the complete array is not divided at once as generally shown
in diagrams. It is solved like a tree problem.

We first solve the extreme left elements and then merge them in sorted order.
Once the complete left half of the array is arranged in sorted order, we move to the right half
and perform the same operation.

After obtaining two completely sorted arrays from left half and right half,
we merge them together in sorted order.
This is how actually merge sort is performed...

*/

#include<bits/stdc++.h>
using namespace std;

void merge_Sort(vector<int>&arr,int start,int end,int mid){
    vector<int>temp;
    int left=start;
    int right=mid+1;
    while(left<=mid && right<=end){         // pushing element when there are elements present in both array
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){                       // when element present only in left side array
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=end){
        temp.push_back(arr[right]);         // when element present only in right side array
        right++;
    }

    for(int i=start;i<=end;i++){            // copy the sorted order of elements into main array
        arr[i]=temp[i-start];
    }
}

void merge(vector<int>&arr,int start,int end){
    if(start>=end) return;                  // base condition ---> when array can not be divided further

    int mid=(end+start)/2;                  // partitioning

    merge(arr,start,mid);
    merge(arr,mid+1,end);
    merge_Sort(arr,start,end,mid);
}

int main(){
    int n;
    cout<<"enter no. of elements :-"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<endl<<"enter elements of the array:- "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge(arr,0,n-1);
    cout<<endl<<"array after applying merge sort :- "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
