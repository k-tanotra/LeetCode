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
    void treeTravel(TreeNode* root){
        if(root==nullptr){
            return;
        }
        if(m.find(root->val)==m.end()){
            m.insert({root->val,1});
        }
        else{
            m[root->val]++;
        }
        treeTravel(root->left);
        treeTravel(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        treeTravel(root);
        bool ans = false;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->first == (k-itr->first) && itr->second>1){
                ans = true;
            }
            else if(itr->first!=(k-itr->first) && m.find(k-(itr->first))!=m.end()){
                ans = true;
            }
        }
        
        return ans;
    }
};