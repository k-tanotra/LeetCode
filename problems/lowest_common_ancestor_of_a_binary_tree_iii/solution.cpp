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
    Node* lowestCommonAncestor(Node* p, Node * q) {
       // int count = 0;
        Node* a = p;
        Node* b = q;
        while(p!=q){
            //count++;
            p = p==nullptr? b:p->parent;
            q = q==nullptr? a:q->parent;
        }
      //  cout<<count;
        return p;
    }
};