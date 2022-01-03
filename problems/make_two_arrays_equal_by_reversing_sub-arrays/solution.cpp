class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m1;
        
        for(int i=0;i<target.size();i++){
            m1[target[i]]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(m1.find(arr[i])==m1.end()){
                return false;
            }
            m1[arr[i]]--;
        }
        
        for(auto itr=m1.begin();itr!=m1.end();itr++){
            if(itr->second!=0){
                return false;
            }
        }
        return true;
    }
};