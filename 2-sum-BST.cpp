/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator{
    stack<TreeNode*>st;
    bool reverse=true;

public:

    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }

   int next(){
        TreeNode* node=st.top();
        st.pop();
        if(reverse==true) 
            pushAll(node->left);
        else 
            pushAll(node->right);
        
        return node->val;
    }

private: 
    void pushAll(TreeNode* root){
        for(;root!=NULL;){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int lval=l.next();
        int rval=r.next();

        while(lval<rval){
            if(lval+rval==k)return true;
            else if(lval+rval<k) lval=l.next();
            else rval=r.next();
        }
        return false;
    }
};
