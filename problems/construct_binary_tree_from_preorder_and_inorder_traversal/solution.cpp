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
    unordered_map<int,int> m;
    int index;
    vector<int> p;
    TreeNode* create(int left,int right){
        if(index==p.size()){
            return nullptr;
        }
        if(left<0){
            return nullptr;
        }
        if(right>p.size()){
            return nullptr;
        }
        if(left>right){
            return nullptr;
        }
        TreeNode* root = new TreeNode();
        root->val = p[index];
        int cur =  index;
        index++;
        root->left = create(left,m[p[cur]]-1);
        root->right = create(m[p[cur]]+1,right);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        m.clear();
        int len = preorder.size();
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
            p.push_back(preorder[i]);
        }
        index = 0;
        root = create(0,len-1);
        return root;
    }
};