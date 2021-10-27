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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while(!q.empty()){
            queue<TreeNode*> t;
            bool f = false;
            int mx;
            while(!q.empty()){
                TreeNode* x = q.front();
                q.pop();
                if(x->left!=nullptr){
                    mx = !f ? x->left->val : max(x->left->val,mx);
                    f = true;
                    t.push(x->left);
                }
                if(x->right!=nullptr){
                    mx = !f ? x->right->val : max(x->right->val,mx);
                    f = true;
                    t.push(x->right);
                }
            }
            if(f)
                ans.push_back(mx);
            while(!t.empty()){
                TreeNode* y = t.front();
                t.pop();
                q.push(y);
            }
        }
        
        return ans;
    }
};