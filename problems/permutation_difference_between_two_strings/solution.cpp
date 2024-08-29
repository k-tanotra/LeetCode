class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> freq(26,0);
        vector<int> freq1(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a'] = i;
            freq1[t[i]-'a'] = i;
        }
        int cnt = 0;
        for(int i=0;i<freq.size();i++){
            cnt +=  abs(freq[i] - freq1[i]);
        }
        return cnt;
    }
};