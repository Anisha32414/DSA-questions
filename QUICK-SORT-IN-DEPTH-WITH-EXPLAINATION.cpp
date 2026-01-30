/*
In quick sort:-

Quick sort works using the divide-and-conquer technique. The main idea is to place one element,
called the pivot, at its correct position in the array such that all elements smaller than or
equal to the pivot are placed on its left side, and all elements greater than the pivot are placed
on its right side.

In the partition function, the first element of the array is chosen as the pivot. Two pointers
are used:-
one pointer starts from the left end of the array, and the other pointer starts from the
right end. 
The left pointer moves forward until it finds an element greater than the pivot, while
the right pointer moves backward until it finds an element less than or equal to the pivot.

If the left pointer is still before the right pointer, the elements at these pointers are swapped.
This process continues until the two pointers cross each other.

Once the pointers cross, the pivot element is swapped with the element at the right pointer. At
this point, the pivot is placed at its correct sorted position in the array.

After partitioning, quick sort is recursively applied to the left subarray and the right subarray
around the pivot. The recursion stops when the subarray has zero or one element, as such subarrays
are already sorted.

This process continues recursively until the entire array is sorted.

*/
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quick_sort(vector<int>&arr,int low, int high){
    if(low<high){
        int index=partition(arr,low,high);
        quick_sort(arr,low,index-1);
        quick_sort(arr,index+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements :- ";
    cin>>n;
    vector<int>arr(n);
    cout<<endl<<"enter the elements of the array :-"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n-1);
    cout<<endl<<"array after quick sort:-"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
