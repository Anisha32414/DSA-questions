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
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        if(root==NULL) return new TreeNode(value);
        TreeNode* node=root;
        while(true){
            if(node->val<value){
                if(node->right!=NULL){
                    node=node->right;
                }
                else{
                    node->right=new TreeNode(value);
                    break;
                }
            }
            else{
                if(node->left!=NULL){
                    node=node->left;
                }
                else{
                    node->left=new TreeNode(value);
                    break;
                }
            }
        }
        return root;
    }
};
