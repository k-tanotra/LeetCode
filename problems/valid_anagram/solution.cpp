class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        return freq1==freq2;
    }
};