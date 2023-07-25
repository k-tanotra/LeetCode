class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> m;

    RandomizedSet() {
        vector<int> v = {};
        unordered_map<int,int> m = {};
    }
    bool insert(int val) {
        if(m.find(val)==m.end() || m[val]==-1){
            m[val] = v.size();
            v.push_back(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end() && m[val]!=-1){
            int index = m[val];
            int lastVal = v[v.size()-1];
            swap(v[index],v[v.size()-1]);
            m[lastVal] = index;
            v.pop_back();
            m[val] = -1;
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return v[rand()%(v.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */