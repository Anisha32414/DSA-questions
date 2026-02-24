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
class Solution {
public:
    void recursion(TreeNode* root,int &res,int curr){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            res+=(curr*2+root->val);
            return;
        }
        recursion(root->left,res,curr*2+root->val);
        recursion(root->right,res,curr*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        recursion(root,res,0);
        return res;
    }
};
