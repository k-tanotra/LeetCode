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
    void treeTravel(TreeNode* root, unordered_map<int,int> &m,int &ans,vector<int> &v){
        if(root==nullptr){
            return;
        }
        treeTravel(root->left,m,ans,v);
        treeTravel(root->right,m,ans,v);
        //  cout<<"HI"<<endl;
        // cout<<root->val<<endl;
        if(m.find(root->val)==m.end()){
            m.insert({root->val,1});
        }
        else{
            m[root->val]++;
        }
        
        if(m[root->val]>ans){
            v.clear();
            ans = m[root->val];
            v.push_back(root->val);
        }
        else if(m[root->val]==ans){
            v.push_back(root->val);
        }
        
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        int ans = -1;
        vector<int> v;
        treeTravel(root,m,ans,v);
        
        // for(auto itr=m.begin();itr!=m.end();itr++){
        //     cout<<itr->first<<" - "<<itr->second<<endl;
        // }
        return v;
        
    }
};