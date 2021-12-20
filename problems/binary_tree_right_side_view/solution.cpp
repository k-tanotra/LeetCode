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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==nullptr){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
            int last;
            while(len){
                TreeNode* x = q.front();
                q.pop();
                last = x->val;
                if(x->left!=nullptr){
                    q.push(x->left);
                }
                if(x->right!=nullptr){
                    q.push(x->right);
                }
                len--;
            }
            v.push_back(last);
        }
        return v;
    }
};