class Solution {
public:
    vector<string> stringSequence(string target) {
        string t= "";
        vector<string> ans;
        for(int i=0;i<target.size();i++){
            string x = t;
            t += target[i];
            int n = target[i]-'a';
            for(int i=0;i<=n;i++){
                string y = x + char('a'+i);
                ans.push_back(y);
            }
        }
        return ans;
    }
};