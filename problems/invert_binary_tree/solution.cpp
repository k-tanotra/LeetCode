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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            TreeNode* temp = nullptr;
            q.pop();
            if(x->left){
                temp = x->left;
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
            x->left = x->right;
            x->right = temp;
        }
        
        return root;
    }
};