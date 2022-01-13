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
    int findDepth(Node* p){
        int d = 0;
        while(p){
            d++;
            p = p->parent;
        }
        return d-1 <0 ? 0 : d-1;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
       int x  = findDepth(p);
       int y  = findDepth(q);
        
       while(x!=y){
           if(x<y){
              q=q->parent;
              y--;
           }
           else{
              p=p->parent;
              x--;
           }
       }
        
        while(p!=q){
            q = q->parent;
            p = p->parent;
        }
        return p;
    }
};