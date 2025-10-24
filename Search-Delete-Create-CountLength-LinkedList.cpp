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
void deleteNode(Node* del){
    del->data=del->next->data;
    del->next=del->next->next;

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
    Node* temp=head;
    for(i=0;i<n;i++){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    if(i==n) cout<<"NULL";


    cout<<endl<<"enter the element you want to search for : "<<endl;
    temp=head;
    int searchElement;
    cin>>searchElement;
    int result=0;
    while(temp!=NULL && temp->data!=searchElement ){
        temp=temp->next;
        result++;
    }
    if(temp==NULL || temp->next==NULL){
        cout<<"element not found !! ";
    }
    else{
        cout<<endl<<searchElement<<" found at index : "<<result<<endl;
    }


    int count=0;
    temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    cout<<"length of the LinkedList is : "<<count<<endl;


    cout<<"enter node to be deleted : ";
    int a;
    cin>>a;
    Node* del=head;

    while(del!=NULL && del->data!=a ){
        del=del->next;
    }
    if(del==NULL || del->next==NULL)
    cout<<"No More Elements !";
    else{
        deleteNode(del);
    }
    
    cout<<endl<<"LinkedList after deletion of given node "<<a<<" is : "<<endl;
    temp=head;
    for(i=0;i<n-1;i++){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    return 0;
}
