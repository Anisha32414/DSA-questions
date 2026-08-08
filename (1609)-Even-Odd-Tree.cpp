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
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0) return false;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            vector<int>curr;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* front=q.front();
                q.pop();
                curr.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(level%2==0){
                if(curr.size()==1 && curr[0]%2==0) return false;
                for(int i=1;i<curr.size();i++){
                    if(curr[i]%2==0) return false;
                    if(curr[i]<=curr[i-1]) return false;
                }
            }
            else{
                if(curr.size()==1 && curr[0]%2!=0) return false;
                for(int i=1;i<curr.size();i++){
                    if(curr[i]%2!=0) return false;
                    if(curr[i]>=curr[i-1]) return false;
                }
            }
            level++;
        }
        return true;
    }
};
