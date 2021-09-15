class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        map<char,int> m;
        int ans = 0;
        int cur = 0;
        int first = 0;
        for(int i=0;i<len;i++){
            if(m.find(s[i])==m.end()){
                m.insert({s[i],i});
                cur++;
                ans = max(cur,ans);
            }
            else{
                // i = m[s[i]];
                if(m[s[i]]<first){
                    cur++;
                    ans = max(cur,ans);
                    m[s[i]] = i;
                    continue;
                }
                if(m[s[i]] >= first ){
                    cur = i - m[s[i]];
                    ans = max(cur,ans);
                    first = m[s[i]] + 1;
                }
                m[s[i]] = i;
            }
        }
        
        return ans;
    }
};