/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void printList(Node* x){
        while(x){
            cout<<x->val<<" ";
            x = x->next;
        }
    }
    
    void printMap1(map<int,Node*> m){
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<itr->second<<endl;
        }
    }
    void printMap2(map<Node*,int> m){
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<itr->second<<endl;
        }
    }
    Node* copyRandomList(Node* head) {
        
        map<int,Node*> m;
        map<Node*,int> m2;
        Node* h1 = head;
        Node* h = nullptr;
        Node* prev = nullptr;
        int index = 0;
        while(head){
            Node* newnode = new Node(head->val);
            if(h==nullptr){
                h=newnode;
            }
            else{
                prev->next = newnode;
            }
            m.insert({index,newnode});
            m2.insert({head,index});
            prev = newnode;
            index++;
            head = head->next;
        }
        Node* cur = h;
        while(h1){
            if(h1->random !=nullptr)
                cur->random = m[m2[h1->random]];
            else
                cur->random = nullptr;
            
            h1 = h1->next;
            cur = cur->next;
        }
        
        return h;
    }
};