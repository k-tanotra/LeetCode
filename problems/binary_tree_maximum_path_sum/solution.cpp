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
    long max(long a,long b){
        if(a>b){
            return a;
        }
        return b;
    }
    long maxP(TreeNode* root,long &ans){
        if(root==nullptr){
            return INT_MIN;
        }
        long left = maxP(root->left,ans);
        long right = maxP(root->right,ans);
        
        // ans = max(ans,max(root->val,max(root->val+left,max(root->val+right,max(root->val+left+right,max(left,right))))));
        // 
        // ans = max(ans,root->val);
        ans = ans>root->val ? ans : root->val;
        ans = ans>root->val +left? ans : root->val + left;
        ans = ans>root->val +right? ans : root->val + right;
        ans = ans>root->val +right + left? ans : root->val + right+left;
        ans = ans>left? ans : left;
        ans = ans>right? ans :right;
        // ans = max(ans,root->val + left);
        // ans = max(ans,root->val + right);
        // ans = max(ans,root->val + left + right);
        // ans = max(ans,left);
        // ans = max(ans,right);
        return max(root->val,max(root->val + left,root->val+right));
    }
    int maxPathSum(TreeNode* root) {
        long ans = INT_MIN;
        maxP(root,ans);
        return ans;
    }
};