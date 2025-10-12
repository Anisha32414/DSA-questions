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

    TreeNode* build(vector<int>& preorder, int preS , int preE , 
        vector<int>& inorder , int inS , int inE , 
        map<int,int>&mp){
        
        if(preS>preE || inS>inE) return NULL;

        TreeNode* root=new TreeNode(preorder[preS]);

        int inRoot=mp[root->val];
        int numsLeft=inRoot-inS;

        root->left=build(preorder , preS+1 , preS + numsLeft , inorder , inS , inRoot - 1 , mp);

        root->right=build(preorder , preS + numsLeft + 1 , preE , inorder , inRoot + 1 , inE , mp);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

        return root;
    }
};
