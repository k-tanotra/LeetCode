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
    void treeAns(TreeNode* root,int &lowest,int depth,int &ans){
        if(root==nullptr){
            return;
        }
        if(depth>lowest){
            lowest = depth;
            ans = root->val;
        }
        treeAns(root->left,lowest,depth+1,ans);
        treeAns(root->right,lowest,depth+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int lowest=-1;
        int ans = -1;
        treeAns(root,lowest,0,ans);
        return ans;
    }
};