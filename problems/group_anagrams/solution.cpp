class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            vector<int> dp(26,0);
            for(int j=0;j<strs[i].length();j++){
                dp[strs[i][j]-'a']++;
            }
            if(m.find(dp)==m.end()){
                vector<string> x;
                x.push_back(strs[i]);
                m.insert({dp,x});
            }
            else{
                m[dp].push_back(strs[i]);
            }
        }
        
        for(auto itr=m.begin();itr!=m.end();itr++){
            ans.push_back(itr->second);
        }
        
        return ans;
    }
};