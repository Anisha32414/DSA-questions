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
    void sumNodes(TreeNode* root,int &res,string curr){
        if(root==NULL) return;

        curr+=root->val+'0';
        if(root->left==NULL && root->right==NULL){
            int num=stoi(curr);
            res+=num;
            return;
        }
        
        sumNodes(root->left,res,curr);
        sumNodes(root->right,res,curr);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        sumNodes(root,res,"");
        return res;
    }
};
