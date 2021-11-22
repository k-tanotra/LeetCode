/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int,Node*> m1;
        map<int,Node*> m2;
         
        queue<Node*> q;
        if(node==nullptr){
            return nullptr;
        }
        int count = 0;
        q.push(node);
        while(!q.empty()){
            Node* x = q.front();
            q.pop();
            // cout<<x->val<<endl;
            if(m1.find(x->val)==m1.end()){
                m1.insert({x->val,x});
                count++;
            }
            else{
                continue;
            }
            Node* newnode = new Node(x->val);
            m2.insert({x->val,newnode});
            vector<Node*> n = x->neighbors;
            for(int i=0;i<n.size();i++){
                if(m1.find(n[i]->val)==m1.end()){
                    q.push(n[i]);
                }
            }
        }
        cout<<count<<endl;
        for(int i=1;i<=count;i++){
            vector<Node*> n = m1[i]->neighbors;
            for(int j=0;j<n.size();j++){
                m2[i]->neighbors.push_back(m2[n[j]->val]);
            }
        }
        return m2[1];
    }
};