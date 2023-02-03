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
    bool traverse(TreeNode* root, TreeNode* root2){
        if(root==nullptr && root2==nullptr){
            return true;
        }
        if((root==nullptr && root2!=nullptr) || (root2==nullptr && root!=nullptr)){
            return false;
        }
        if(root->val!=root2->val){
            return false;
        }
        return (traverse(root->left,root2->left) || traverse(root->left,root2->right)) &&
                 (traverse(root->right,root2->left) || traverse(root->right,root2->right));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return traverse(root1,root2);
    }
};