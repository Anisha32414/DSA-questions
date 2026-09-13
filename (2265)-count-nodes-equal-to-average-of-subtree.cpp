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
    pair<int,int> traverse(TreeNode* node,int &count){
        if(node==NULL) return {0,0};

        auto [leftsum,leftcnt]=traverse(node->left,count);
        auto [rightsum,rightcnt]=traverse(node->right,count);

        int subtree_sum=leftsum+rightsum+node->val;
        int subtree_cnt=leftcnt+rightcnt+1;

        if(subtree_sum/subtree_cnt==node->val) count++;

        return {subtree_sum,subtree_cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        traverse(root,count);
        return count;
    }
};
