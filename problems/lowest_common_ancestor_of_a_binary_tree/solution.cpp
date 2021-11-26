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
    TreeNode* ans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==p->val){
            return root;
        }
        if(root->val==q->val){
            return root;
        }
        TreeNode* left = ans(root->left,p,q);
        TreeNode* right = ans(root->right,p,q);
        if(left && right){
            return root;
        }
        if(left){
            return left;
        }
        else{
            return right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ans(root,p,q);
    }
};