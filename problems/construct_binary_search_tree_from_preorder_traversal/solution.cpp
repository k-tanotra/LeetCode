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
    TreeNode* create(int start,int end,vector<int>& preorder){
        if(start>end){
            return nullptr;
        }
        if(start==end){
            TreeNode* y = new TreeNode(preorder[start]);
            return y;
        }
        int b = end+1;
        for(int i=start+1;i<=end;i++){
            if(preorder[i]>preorder[start]){
                b = i;
                break;
            }
        }

        TreeNode* x = new TreeNode(preorder[start],create(start+1,b-1,preorder),create(b,end,preorder));
        return x;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return create(0,n-1,preorder);
    }
};