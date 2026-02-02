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
    void paths(TreeNode* root,vector<string>&result,string term){
        if(root==nullptr){
            return;
        }
        
        term+=to_string(root->val);

        if(root->left==nullptr && root->right==nullptr){
            result.push_back(term);
            return;
        }
        term+="->";
        paths(root->left,result,term);
        paths(root->right,result,term);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        string term="";
        paths(root,result,term);
        return result;
    }
};
