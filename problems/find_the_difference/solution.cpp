class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq1(26,0);
        
        int n = s.length();
        for(int i=0;i<n;i++){
            freq1[s[i]-'a']++;
        }
        
        int m = t.length();
        for(int i=0;i<m;i++){
            freq1[t[i]-'a']--;
        }
        char ans;
        for(int i=0;i<26;i++){
            if(freq1[i]!=0)
                ans =  'a' + i;
        }
        
        return ans;
    }
};