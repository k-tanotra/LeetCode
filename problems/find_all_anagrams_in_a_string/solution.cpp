class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()){
            return {};
        }
        vector<int> freq(26,0);
        vector<int> ans;
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
        }
        int start = 0;
        vector<int> window(26,0);
        for(int i=0;i<p.length();i++){
            window[s[i]-'a']++;
        }
        if(window==freq){
            ans.push_back(start);
        }
        
        for(int i=p.length();i<s.length();i++){
            window[s[start]-'a']--;
            start++;
            window[s[i]-'a']++;
            if(window==freq){
                ans.push_back(start);
            }
        }
        return ans;
    }
};