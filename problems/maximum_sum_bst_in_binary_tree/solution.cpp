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
    vector<int> treeTravel(TreeNode* root,int *p){
        if(root==nullptr){
            return {0,INT_MIN,INT_MAX};
        }
        vector<int> a;
        vector<int> b;
        
        (root->left==nullptr) ? a = {0,root->val-1,root->val-1} : a = treeTravel(root->left,p);
        (root->right==nullptr) ? b = {0,root->val+1,root->val+1} : b = treeTravel(root->right,p);
        if(a[0]==INT_MIN|| b[0]==INT_MIN){
            return {INT_MIN,INT_MIN,INT_MAX};
        }
        else if(a[1]>root->val || a[2]>root->val || b[1]<root->val || b[2]<root->val){
            return {INT_MIN,INT_MIN,INT_MAX};
        }
        else{
            *p = max(a[0]+b[0]+root->val,*p);
            return {a[0]+b[0]+root->val,a[1],b[2]};
        }
        
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        treeTravel(root,&ans);
        return ans;
    }
};