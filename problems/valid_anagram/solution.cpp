class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int c1[26] = {0};
        for(int i=0;i<s.length();i++){
            c1[s[i]-'a']++;
            c1[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(c1[i]!=0){
                return false;
            }
        }
        return true;
    }
};