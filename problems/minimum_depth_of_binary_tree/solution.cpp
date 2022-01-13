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
    int minDepth(TreeNode* root) {
        int d = 0;
        if(!root)
            return d;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            d++;
            int n = q.size();
            while(n>0){
                if(!q.front()->left && !q.front()->right)
                    return d;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                n--;
                q.pop();
            }
        }
        
        return d;
    }
};