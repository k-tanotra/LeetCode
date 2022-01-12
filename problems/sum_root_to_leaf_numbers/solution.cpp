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
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right)
            return true;
        return false;
    }
    void rec(TreeNode* root,int cur,int &sum){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            sum+=cur*10+root->val;
            return;
        }
        rec(root->left,cur*10+root->val,sum);
        rec(root->right,cur*10+root->val,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        rec(root,0,sum);
        return sum;
    }
};