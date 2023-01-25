class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return  false;
        }
        unordered_map<char,char> m;
        unordered_map<char,char> m2;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end() && m2.find(t[i])==m2.end()){
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if(m.find(s[i])==m.end() && m2.find(t[i])!=m2.end()){
                return false;
            }
            else if(m.find(s[i])!=m.end() && m2.find(t[i])==m2.end()){
                return false;
            }
            else if(m.find(s[i])!=m.end() && m2.find(t[i])!=m2.end()){
                if(m[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};