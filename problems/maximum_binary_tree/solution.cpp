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
    vector<int> v;
    TreeNode* mBST(int s,int e){
        if(s>e){
            return nullptr;
        }
        else if(s<0 || e>=v.size()){
            return nullptr;
        }
        int mx = -1;
        int id;
        for(int i=s;i<=e;i++){
            if(v[i]>mx){
                mx = v[i];
                id = i;
            }
        }
        
        TreeNode* x = new TreeNode();
        x->val = mx;
        x->left = mBST(s,id-1);
        x->right = mBST(id+1,e);
        return x;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        v = nums;
        int n = nums.size();
        return mBST(0,n-1);
    }
};