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
    void travel(TreeNode* root,int &ans){
        if(root==nullptr){
            return;
        }
        travel(root->right,ans);
        int temp = root->val;
        root->val +=ans;
        ans +=temp;
        travel(root->left,ans);
        
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        int ans=0;
        travel(root,ans);
        return root;
    }
};