/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int travel(Node* root,int &ans){
        if(!root){
            return 0;
        }
        int a = 0;
        int b = 0;
        for(int i=0;i<root->children.size();i++){
            int x = travel(root->children[i],ans);
            if(x>a){
                b = a;
                a = x;
            }
            else if(x>b){
                b = x;
            }
        }
        ans = max(max(max(a,b),a+b),ans);
        //cout<<root->val<<" -- "<<a<<" -- "<<b<<" -- "<<ans<<endl;
        return max(a+1,b+1);
    }
    int diameter(Node* root) {
        int ans = 0;
        travel(root,ans);
        return ans;
    }
};