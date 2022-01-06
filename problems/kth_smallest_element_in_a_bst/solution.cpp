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
    int c;
    int ans;
    
    void travel(TreeNode* root,int k){
        if(root==nullptr || ans!=-1){
            return;
        }
        travel(root->left,k);
        c = c+1;
        if(c==k){
            ans = root->val;
        }
        travel(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        c = 0;
        ans=-1;
        travel(root,k);
        return ans;
    }
};