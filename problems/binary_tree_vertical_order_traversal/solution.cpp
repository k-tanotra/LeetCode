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
    //DFS Terms
    /*
    map<int,map<int,vector<int>>> m;
    void travel(TreeNode* root,int col,int depth){
        if(!root){
            return;
        }
        m[col][depth].push_back(root->val);
        travel(root->left,col-1,depth+1);
        travel(root->right,col+1,depth+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        travel(root,0,0);
        for(auto itr=m.begin();itr!=m.end();itr++){
            vector<int> tp;
            map<int,vector<int>> mp = itr->second;
            for(auto itr2=mp.begin();itr2!=mp.end();itr2++){
                tp.insert(tp.end(),itr2->second.begin(),itr2->second.end());
            }
            ans.push_back(tp);
        }
        return ans;
    }*/
    
    //BFS Terms
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<pair<int,TreeNode*>> q;
        unordered_map<int,vector<int>> m;
        q.push({0,root});
        int mnCol = 0;
        int mxCol = 0;
        while(!q.empty()){
            m[q.front().first].push_back(q.front().second->val);
            if(q.front().second->left){
                mnCol = min(q.front().first-1,mnCol);
                q.push({q.front().first-1,q.front().second->left});
            }
            if(q.front().second->right){
                mxCol = max(q.front().first+1,mxCol);
                q.push({q.front().first+1,q.front().second->right});
            }
            q.pop();
        }
        
        vector<vector<int>> ans;
        for(int i=mnCol;i<=mxCol;i++){
            if(m.find(i)!=m.end())
                ans.push_back(m[i]);
        }
        return ans;
    }
};