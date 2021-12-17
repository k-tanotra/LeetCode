/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    unordered_set<int> s;
    void travel(Node* p,Node* &ans,bool &found){
        if(p==nullptr){
            return;
        }
        if(found){
            return;
        }
        if(s.find(p->val)==s.end()){
            s.insert(p->val);
        }
        else{
            ans = p;
            found = true;
            return;
        }
        travel(p->parent,ans,found);
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* ans;
        bool found = false;
        travel(p,ans,found);
        travel(q,ans,found);
        return ans;
    }
};