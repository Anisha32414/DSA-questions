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

int floorValue(TreeNode* root,int value){
    int ans=-1;
    while(root){
        if(root->val==value){
            ans=root->val;
            return ans;
        }
        if (root->val > value) {   
            root = root->left; // try to find smaller one
        } else {
            ans = root->val;   //may be floor
            root = root->right; // go right to find bigger one
        }
    }
    return ans;
}

int main(){
    TreeNode* root=createTree();
    int value;
    cin>>value;
    int res=floorValue(root,value);
    cout<<"the ceil value for "<<value<<" is : "<<res;
    return 0;
}
