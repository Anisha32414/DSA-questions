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
    bool univalued(TreeNode* node,int num){
        if(node==NULL) return true;
        if(node->val!=num) return false;
        bool l=univalued(node->left,num);
        bool r=univalued(node->right,num);
        return (l && r);
    }
    bool isUnivalTree(TreeNode* root) {
        return univalued(root,root->val);
    }
};
