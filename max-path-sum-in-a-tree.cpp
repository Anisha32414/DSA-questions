#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;

    node(int x){
        val=x;
        right=NULL;
        left=NULL;
    }
};

int max_path_sum(node* head,int &max_sum){
    if(head==NULL){
        return 0;
    }
    int l=max(0,max_path_sum(head->left,max_sum));

    int r=max(0,max_path_sum(head->right,max_sum));
    
    int curr_path=l+r+head->val;
    max_sum=max(max_sum,curr_path);

    return head->val+max(l,r);
}

int main(){
    
    node *head=new node(-10);
    head->left=new node(4);
    head->right=new node(7);
    head->right->left=new node(8);
    head->right->right=new node(10);
    int max_sum=INT_MIN;

    max_path_sum(head,max_sum);
    cout<<"max path sum in given tree is : "<<max_sum;
    return 0;
}
//answer : 25
