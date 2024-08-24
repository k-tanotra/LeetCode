class Solution {
public:
    int numSplits(string s) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int sz = 0;
        int sz2 = 0;
        for(int i=0;i<s.size();i++){
            if(freq1[s[i]-'a']==0){
                sz++;
            }
            freq1[s[i]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<s.size()-1;i++){
            freq1[s[i]-'a']--;
            if(freq1[s[i]-'a']==0){
                sz--;
            }
            if(freq2[s[i]-'a']==0){
                sz2++;
            }
            freq2[s[i]-'a']++;
            if(sz==sz2){
                ans++;
            }
        }
        return ans;
    }
};