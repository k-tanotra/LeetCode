class LRUCache {
public:
    struct node{
       int key;
       int val;
       node* next;
       node* prev;
    };
    
    node* head = nullptr;
    node* tail = nullptr;
    int size;
    int curSize;
    unordered_map<int,node*> m;
    LRUCache(int capacity) {
        this->size = capacity;
        this->curSize = 0;
    }
    
    node* addtofront(int key,int val){
        node* newnode = new node();
        newnode->key = key;
        newnode->val = val;
        newnode->next = head;
        if(head!=nullptr){
            head->prev = newnode;
        }
        else{
            this->tail = newnode;
        }
        newnode->prev = nullptr;
        this->head = newnode;
        return newnode;
    }
    void removeTail(){
        node* temp = this->tail;
        this->tail = this->tail->prev;
        if(this->tail==nullptr){
            head = nullptr;
        }
        else{
            this->tail->next = nullptr;   
        }
        delete temp;
    }
    void removeNode(node* n){
        if(n==this->head){
            this->head = this->head->next;
            if(this->head!=nullptr){
                this->head->prev = nullptr;   
            }
            else{
                this->tail = nullptr;
            }
            delete n;
        }
        else if(n==this->tail){
            this->tail = this->tail->prev;
            if(this->tail!=nullptr){
                 this->tail->next = nullptr;   
            }
            else{
                this->head = nullptr;
            }
            delete n;
        }
        else{
            n->next->prev = n->prev;
            n->prev->next = n->next;
            delete n;
        }
    }
    
    void print(){
        node* cur = head;
        while(cur){
            cout<<cur->val<<endl;
            cur=cur->next;
        }
        
        cout<<endl;
        cur = tail;
        while(cur){
            cout<<cur->val<<endl;
            cur = cur->prev;
        }
    }
    
    void printMap(){
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<" "<<itr->second->val<<endl;
        }
    }
    int get(int key) {
        if(m.find(key)==m.end() || m[key]==nullptr){
            return -1;
        }
        int ans = m[key]->val;
        put(key,m[key]->val);
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end() || m[key]==nullptr){
            if(curSize<size){
                m[key] = addtofront(key,value);
                this->curSize++;
            }
            else{
                m[tail->key] = nullptr;
                removeTail();
                m[key] = addtofront(key,value);
            }
        }
        else{
            removeNode(m[key]);
            m[key] = addtofront(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */