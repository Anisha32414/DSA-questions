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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* node=root;
        while(node!=NULL){
            if(node->val>key){
                if(node->left!=NULL && node->left->val==key){
                    node->left=helper(node->left);
                    break;
                }
                else{
                    node=node->left;
                }
            }
            else{
                if(node->right!=NULL && node->right->val==key){
                    node->right=helper(node->right);
                    break;
                }
                else{
                    node=node->right;
                }
            }
        }
        return root;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightNode=root->right;
        TreeNode* lastRight=lastRightNode(root->left);

        lastRight->right=rightNode;

        return root->left;
    }

    TreeNode* lastRightNode(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return lastRightNode(root->right);
    }
};
