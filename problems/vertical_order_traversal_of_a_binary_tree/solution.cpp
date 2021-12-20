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
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second){
            return true;
        }
        else if(a.second==b.second){
            if(a.first<b.first){
                return true;
            }
        }
        return false;
    }
    map<int,vector<pair<int,int>>> m;
    void dfs(TreeNode* root,int pos,int depth){
        if(root==nullptr){
            return;
        }
        if(m.find(pos)==m.end()){
            vector<pair<int,int>> x;
            x.push_back({root->val,depth});
            m.insert({pos,x});
        }
        else{
            m[pos].push_back({root->val,depth});
        }
        
        dfs(root->left,pos-1,depth+1);
        dfs(root->right,pos+1,depth+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        for(auto itr=m.begin();itr!=m.end();itr++){
            sort(itr->second.begin(),itr->second.end(),cmp);
            vector<int> x;
            for(int i=0;i<itr->second.size();i++){
                x.push_back(itr->second[i].first);
            }
            ans.push_back(x);
        }
        return ans;
    }
};