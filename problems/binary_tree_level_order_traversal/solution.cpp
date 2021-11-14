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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size>0){
                TreeNode* x = q.front();
                v.push_back(x->val);
                q.pop();
                if(x->left!=nullptr){
                    q.push(x->left);
                }
                if(x->right!=nullptr){
                    q.push(x->right);
                }
                size--;
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};