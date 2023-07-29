class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int tot = words.size();
        int len = words[0].size();
        int concatLen = tot*len;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<s.size()-concatLen+1;i++){
            unordered_map<string,int> m2;
            for(int j=0;j<tot;j++){
                string temp = s.substr(i+j*len,len);
                m2[temp]++;
            }
            if(m2==m){
                ans.push_back(i);
            }
        }
        return ans;
    }
};