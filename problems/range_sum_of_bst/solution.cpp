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
    void travel(TreeNode* root,int low,int high,int &sum){
        if(root==nullptr){
            return;
        }
        if(root->val>high){
            return travel(root->left,low,high,sum);
        }
        else if(root->val<low){
            return travel(root->right,low,high,sum);
        }
        //cout<<root->val<<endl;
        if(root->val>=low && root->val<=high){
            sum += root->val;
        }
        travel(root->left,low,high,sum);
        travel(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        travel(root,low,high,sum);
        return sum;
    }
};