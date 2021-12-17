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
    map<int,map<int,vector<int>>> m;
    void travel(TreeNode* root,int pos,int d){
        if(root==nullptr){
            return;
        }
        //cout<<root->val<<endl;
        m[pos][d].push_back(root->val);
        travel(root->left,pos-1,d+1);
        travel(root->right,pos+1,d+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        travel(root,0,0);
        vector<vector<int>> ans;
        for(auto itr=m.begin();itr!=m.end();itr++){
            vector<int> t;
            for(auto itr2=itr->second.begin();itr2!=itr->second.end();itr2++){
                t.insert(t.end(),itr2->second.begin(),itr2->second.end());
            }
            ans.push_back(t);
        }
        return ans;
    }
};