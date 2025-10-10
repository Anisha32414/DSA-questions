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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int res=0;
        while(!q.empty()){
            int min_ind=q.front().second;
            int s=q.size();
            int first,last;
            for(int i=0;i<s;i++){
                int cur_ind=q.front().second-min_ind;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0) first=cur_ind;
                if(i==s-1) last=cur_ind;

                if(node->left) q.push({node->left,1LL*(cur_ind)*2+1});
                if(node->right) q.push({node->right,1LL*(cur_ind)*2+2});
            }
            res=max(res,last-first+1);
        }
        return res;
    }
};
