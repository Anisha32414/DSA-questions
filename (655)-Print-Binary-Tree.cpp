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
    int height(TreeNode* node){
        if(node==NULL) return 0;
        if(node->left==NULL && node->right==NULL) return 1;
        return 1+max(height(node->left),height(node->right));
    }
    void matrix(TreeNode* node,vector<vector<string>>&res,int r,int c,int height){
        if(node==NULL) return;

        res[r][c]=to_string(node->val);
        if(node->left){
            int row=r+1;
            int col=c-(1<<(height-r-1));
            matrix(node->left,res,row,col,height);
        }
        if(node->right){
            int row=r+1;
            int col=c+(1<<(height-r-1));
            matrix(node->right,res,row,col,height);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root)-1;
        int n=(1<<(h+1))-1;
        vector<vector<string>>res(h+1,vector<string>(n,""));

        matrix(root,res,0,(n-1)/2,h);
        return res;
    }
};
