#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int n) : val(n), left(NULL) , right(NULL){}
};

TreeNode* createTree(){
    int rootVal;
    cin>>rootVal;

    if(rootVal==-1) return NULL;

    TreeNode* root=new TreeNode(rootVal);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();

        int l,r;
        cin>>l;
        cin>>r;

        if(l!=-1){
            curr->left=new TreeNode(l);
            q.push(curr->left);
        }

        if(r!=-1){
            curr->right=new TreeNode(r);
            q.push(curr->right);
        }
    }
    return root;
}

int ceilValue(TreeNode* root,int value){
    int ans=-1;
    while(root){
        if(root->val==value){
            ans=root->val;
            return ans;
        }
        if (root->val > value) {
            ans = root->val;   // possible ceil
            root = root->left; // try to find smaller one
        } else {
            root = root->right; // go right to find bigger one
        }
    }
    return ans;
}

int main(){
    TreeNode* root=createTree();
    int value;
    cin>>value;
    int res=ceilValue(root,value);
    cout<<"the ceil value for "<<value<<" is : "<<res;
    return 0;
}
