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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<pair<int,TreeNode*>> q;
        unordered_map<int,unordered_map<int,vector<int>>> m;
        q.push({0,root});
        int depth = 0;
        int mnCol = 0;
        int mxCol = 0;
        while(!q.empty()){
            int n = q.size();
            while(n>0){
                if(q.front().second->left){
                    q.push({q.front().first-1,q.front().second->left});
                    mnCol = min(mnCol,q.front().first-1);
                }
                if(q.front().second->right){
                    q.push({q.front().first+1,q.front().second->right});
                    mxCol = max(mxCol,q.front().first+1);
                }
                m[q.front().first][depth].push_back(q.front().second->val);
                q.pop();
                n--;
            }
            depth++;
        }
        
        vector<vector<int>> ans;
        for(int i=mnCol;i<=mxCol;i++){
            unordered_map<int,vector<int>> m2 = m[i];
            vector<int> t;
            for(int j=0;j<depth;j++){
                if(m2.find(j)!=m2.end()){
                    sort(m2[j].begin(),m2[j].end());
                    t.insert(t.end(),m2[j].begin(),m2[j].end());
                }
            }
            ans.push_back(t);
        }
        
        return ans;
    }
};