#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
    node(int x){
        val=x;
        next=NULL;
    }
};

node* insert_node(node* head,int data){
    node* ele=new node(data);
    if(head==NULL){
        head=ele;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ele;
    return head;
}
node* insert_data(node* head,node* new_node){
    node* slow=head;
    node* fast=head;
    node* prev=NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=new_node;
    new_node->next=slow;

    return head;
}
void print_ll(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    int i=0;
    node* head=NULL;

    while(i<n){
        int data;
        cin>>data;
        head=insert_node(head,data);
        i++;
    }

    int data_to_insert;
    cin>>data_to_insert;
    cout<<"data before inserting node at middle\n";
    print_ll(head);

    node* new_data=new node(data_to_insert);
    head=insert_data(head,new_data);
    cout<<"\ndata after inserting node at middle\n";
    print_ll(head);

    return 0;
}
