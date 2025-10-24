#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* arrayToLL(vector<int>&nums,int n){
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* node=new Node(nums[i]);
        mover->next=node;
        mover=node;
    }
    return head;
}

int main(){
    int n;
    cout<<"no. of elements in array -> to be converted into LL : "<<endl;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<endl;
    cout<<"array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<"L.L. is : "<<endl;
    Node* head=arrayToLL(nums,n);
    int i;
    for(i=0;i<n;i++){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    if(i==n) cout<<"NULL";
    
    return 0;
}
