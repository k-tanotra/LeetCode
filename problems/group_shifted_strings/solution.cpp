class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> m;
        int n = strings.size();
        for(int i=0;i<n;i++){
            string ky = "|";
            int pat = 0;
            for(int j=0;j<strings[i].size()-1;j++){
                pat = strings[i][j+1] - strings[i][j];
                if(pat<0)
                    pat = 26 + pat;
                ky += 'a' + pat;
            }
            if(m.find(ky)==m.end()){
                m.insert({ky,{strings[i]}});
            }
            else{
                m[ky].push_back(strings[i]);
            }
        }
        
        vector<vector<string>> ans;
        for(auto itr=m.begin();itr!=m.end();itr++){
            ans.push_back(itr->second);
        }
        
        return ans;
    }
};