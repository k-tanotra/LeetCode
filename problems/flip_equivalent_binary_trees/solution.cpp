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
    bool rec(TreeNode* root1, TreeNode* root2){
        bool swap = false;
        if(!root1 && !root2){
            return true;
        }
        else if((!root1 && root2) || (!root2 && root1) || (root1->val!=root2->val)){
            return false;
        }
        int left1 = -1;
        int left2 = -1;
        int right1 = -1;
        int right2 = -1;
        int act1 = 0;
        int act2 = 0;
        
        cout<<root1->val<<" "<<root2->val<<endl;
        if(root1->left){
            left1 = root1->left->val;
            act1++;
        }
        if(root2->left){
            left2 = root2->left->val;
            act2++;
        }
        if(root1->right){
            right1 = root1->right->val;
            act1++;
        }
        if(root2->right){
            act2++;
            right2 = root2->right->val;
        }
        
        if(act2!=act1){
            return false;
        }
        
        if(left1!=left2 && left1!=right2){
            return false;
        }
        if(right1!=right2 && right1!=left2){
            return false;
        }
        
        if(left1!=left2 && left1==right2){
            swap = true;
            TreeNode* x = root2->right;
            root2->right = root2->left;
            root2->left = x;
        }
        
        if(right1!=right2 && right1==left2 && !swap){
            swap = true;
            TreeNode* x = root2->right;
            root2->right = root2->left;
            root2->left = x;
        }
        
        return rec(root1->left,root2->left) && rec(root1->right,root2->right);
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){
            return true;
        }
        return rec(root1,root2);
    }
};