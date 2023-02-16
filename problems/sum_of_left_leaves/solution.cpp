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
    void traverse(TreeNode* root,int &sum, int prev){
        if(!root){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(prev==1)
                sum += root->val;
        }
        traverse(root->left,sum,1);
        traverse(root->right,sum,-1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root,sum,0);
        return sum;
    }
};