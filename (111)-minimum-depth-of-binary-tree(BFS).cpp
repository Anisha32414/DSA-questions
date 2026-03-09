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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,1});

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            TreeNode* node=it.first;
            int depth=it.second;
            if(node->left==NULL && node->right==NULL) return depth;

            if(node->left) q.push({node->left,depth+1});
            if(node->right) q.push({node->right,depth+1});
        }
        return 0;
    }
};
