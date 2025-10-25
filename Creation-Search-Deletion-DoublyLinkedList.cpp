#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int x){
        data=x;
        prev=nullptr;
        next=nullptr;
    }

    Node(int y,Node* prev1,Node* next1){
        data=y;
        prev=prev1;
        next=next1;
    
    }
};


Node* createDLL(vector<int>&arr,int n){           //create DLL
    Node* head=new Node(arr[0]);
    Node* pre=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i],pre,nullptr);
        pre->next=temp;
        pre=temp;
    }
    return head;
}


void printDLL(Node* head){
    cout<<endl<<"Doubly LL is : "<<endl;
    Node* node=head;
    while(node!=NULL){                           //print DLL
        cout<<node->data<<" <-> ";
        node=node->next;
    }
    cout<<"null";
}
int searchElement(Node* head,int search){
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL && temp->data!=search){
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL){
        return 0;
    }
    else{
        return cnt;
    }
    return 0;
}


Node* deleteElement(Node* head,int delElement){
    Node* temp=head;
    while(temp!=NULL && temp->data!=delElement){
        temp=temp->next;
    }

    if(temp==NULL){
        cout<<"no such element in DLL";
        return head;
    }
    else{

        Node* upcoming=temp->next;
        Node* back=temp->prev;
        if(upcoming==NULL && back==NULL){
            delete temp;
            return NULL;
          
        }
        else if(upcoming==NULL){
            back->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else if(back==NULL){
            upcoming->prev=NULL;
            temp->next=NULL;
            head=upcoming;
            delete temp;
        }
        else{
            back->next=upcoming;
            upcoming->prev=back;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
           
        }
    }
    return head;
}

int main(){
    int n;
    cout<<"enter size of array : "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"elements of array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    Node* head=createDLL(arr,n);

    printDLL(head);



    int search;
    cout<<endl<<"enter element you want to search for"<<endl;
    cin>>search;
    int result=searchElement(head,search);
    if(result){
        cout<<search<<" found at index : "<<result-1;
    }
    else{
        cout<<"element not found in DLL ! ! ";
    }



    int delElement;
    cout<<endl<<"enter element you want to delete : "<<endl;
    cin>>delElement;
    head=deleteElement(head,delElement);
    cout<<endl<<"DLL after deletion of : "<<delElement<<endl;
    printDLL(head);

    return 0;
}
