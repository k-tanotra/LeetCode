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
    void print(vector<int> f){
        for(int i=0;i<f.size();i++){
            cout<<i+1<<" -- "<<f[i]<<endl;
        }
        cout<<"END"<<endl;
    }
    bool check(vector<int> &freq){
        int odd = 0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]%2!=0){
                odd++;
            }
        }
        return odd>1 ? false:true;
    }
    bool isLeaf(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    void traverse(TreeNode* root,vector<int> freq,int* p){
        freq[root->val-1]++;
        if(isLeaf(root)){
            if(check(freq)){
                (*p)++;
            }
            return;
        }
        if(root->right!=nullptr)
            traverse(root->right,freq,p);
        if(root->left!=nullptr)
            traverse(root->left,freq,p);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> freq(9,0);
        traverse(root,freq,&ans);
        return ans;
    }
};