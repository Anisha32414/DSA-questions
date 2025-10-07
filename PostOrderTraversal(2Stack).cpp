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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        if(root==NULL)
           return res;
           
        st1.push(root);

        while(!st1.empty()){
            root=st1.top();
            st2.push(root);
            st1.pop();

            if(root->left!=NULL)
               st1.push(root->left);
            if(root->right!=NULL)
               st1.push(root->right);
        }
        while(!st2.empty()){
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};
