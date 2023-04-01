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
    void traverse(TreeNode* root,int* sum,int depth,int* mxDepth){
        if(!root)
            return;
        if(depth>*mxDepth){
            *mxDepth = depth;
            (*sum) = 0;
        }
        //cout<<depth<<" "<<(*sum)<<" "<<root->val<<" "<<mxDepth<<endl;
        if(root->left==nullptr && root->right==nullptr && depth==*mxDepth){
           // cout<<root->val<<endl;
            (*sum) += root->val;
        }
        traverse(root->left,sum,depth+1,mxDepth);
        traverse(root->right,sum,depth+1,mxDepth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0; 
        int mxDepth =-1;
        traverse(root,&sum,0,&mxDepth);
        return sum;
    }
};