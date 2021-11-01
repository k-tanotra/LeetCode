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
    int rec(TreeNode* root,int &ans){
        if(root==nullptr){
            return 0;
        }
        int a = rec(root->left,ans);
        int b = rec(root->right,ans);
        ans = max(max(max(a,b),a+b),ans);
        return max(a+1,b+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = -1;
        rec(root,ans);
        return ans;
    }
};