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
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        if(root->val>p->val && root->val<q->val){
            return root;
        }
        else if(root->val>p->val && root->val>q->val){
            return ans(root->left,p,q);
        }
        else{
            return ans(root->right,p,q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x = p;
        if(p->val > q->val){
            p = q;
            q = x;
        }
        return ans(root,p,q);
    }
};