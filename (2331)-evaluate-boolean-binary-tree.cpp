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
    bool ans=false;
    bool res(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            if(node->val==0) return false;
            else return true;
        }
        if(node->val==2){
            ans=(res(node->left) || res(node->right));
        }
        else{
            ans=(res(node->left) && res(node->right));
        }
        return ans;
    }
    bool evaluateTree(TreeNode* root) {
        return res(root);
    }
};
