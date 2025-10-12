/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trackParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right]=current;
                q.push(current->right);
            }
        }
    }

    int timeToBurnTree(TreeNode* root, TreeNode* target) {
       
        unordered_map<TreeNode*,TreeNode*>parent_track;
        trackParent(root,parent_track);
        
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int time=0;

        while(!q.empty()){
            int s=q.size();
            bool burned=false;

            for(int i=0;i<s;i++){
                TreeNode* current=q.front();
                q.pop();

                if(current->left && !visited[current->left]){
                    visited[current->left]=true;
                    q.push(current->left);
                    burned=true;
                }
                if(current->right && !visited[current->right]){
                    visited[current->right]=true;
                    q.push(current->right);
                    burned=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    visited[parent_track[current]]=true;
                    q.push(parent_track[current]);
                    burned=true;
                }
            }
            if(burned) time++;
        }
        return time;
    }
};
