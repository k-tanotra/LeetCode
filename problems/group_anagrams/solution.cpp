class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> m;
        vector<vector<string>> v;
        for(int i=0;i<strs.size();i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            if(m.find(x)==m.end()){
                int idx = v.size();
                v.push_back({strs[i]});
                m[x] = idx;
            }
            else{
                v[m[x]].push_back(strs[i]);
            }
        }
        return v;
    }
};