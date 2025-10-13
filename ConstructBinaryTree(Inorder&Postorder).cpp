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
    TreeNode* build(vector<int>& inorder,int inS , int inE , 
    vector<int>& postorder , int postS , int postE , map<int,int>&mp){
        if(inS>inE || postS>postE) return NULL;

        TreeNode* root=new TreeNode(postorder[postE]);

        int rootin=mp[root->val];
        int numsleft=rootin-inS;

        root->left=build(inorder,inS,rootin-1,postorder,postS,postS+numsleft-1,mp);

        root->right=build(inorder,rootin+1,inE,postorder,postS+numsleft,postE-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode* root=build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);

        return root;
    }
};

