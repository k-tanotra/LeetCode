class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int mxLen = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]] = i;
            }
            else{
                start = max(m[s[i]] + 1,start);
                m[s[i]] = i;
            }
            mxLen = max(mxLen,i-start+1);
        }
        return mxLen;
    }
};