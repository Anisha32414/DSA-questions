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
    void depth(TreeNode* root,int &res,int cnt){
        if(root==NULL){
            return;
        }
        if(root->right==NULL && root->left==NULL){
            res=min(res,cnt);
            return;
        }
        depth(root->left,res,cnt+1);
        depth(root->right,res,cnt+1);
    }
    int minDepth(TreeNode* root) {
        int res=INT_MAX;
        int cnt=1;

        if(root==NULL) return 0;

        depth(root,res,cnt);
        return res;
    }
};
