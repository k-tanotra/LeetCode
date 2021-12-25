class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        sort(changed.begin(),changed.end());
        int n = changed.size();
        if(n%2!=0){
            return ans;
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(changed[i])==m.end()){
                m.insert({changed[i],1});
            }
            else{
                m[changed[i]]++;
            }
        }
        int sz = 0;
        for(int i=0;i<n;i++){
            if(m[changed[i]]!=0){
                if(m.find(changed[i]*2)!=m.end() && m[changed[i]*2]!=0){
                    m[changed[i]]--;
                    if(m[changed[i]*2]!=0){
                        m[changed[i]*2]--;
                        ans.push_back(changed[i]);
                       //ans.push_back(changed[i]*2);
                        sz++;
                    }
                }
            }
        }
        if(sz*2==n){
            return ans;
        }
        return {};
    }
};