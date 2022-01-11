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
    
    void travel(TreeNode* root,int depth,vector<int> &ans){
        if(!root){
            return;
        }
        if(ans.size()<depth){
            ans.push_back(root->val);
        }
        travel(root->right,depth+1,ans);
        travel(root->left,depth+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        //dfs
        vector<int> ans;
        travel(root,1,ans);
        return ans;
        
    }
};