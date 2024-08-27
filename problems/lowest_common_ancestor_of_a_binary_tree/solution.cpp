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
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr){
            return nullptr;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* l = rec(root->left,p,q);
        TreeNode* r = rec(root->right,p,q);
        if(l!=nullptr && r==nullptr){
            return l;
        }
        if(l==nullptr && r!=nullptr){
            return r;
        }
        if(l!=nullptr && r!=nullptr){
            return root;
        }
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};