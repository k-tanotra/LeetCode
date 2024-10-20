class Solution {
public:
    bool check(vector<int> &a,vector<int> &b,int k){

        for(int i=0;i<a.size();i++){
            if(b[i]-a[i]>=k){
                return true;
            }
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        vector<vector<int>> prefix;
        vector<int> freq(26,0);
        prefix.push_back(freq);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            prefix.push_back(freq);
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(prefix[i],prefix[j+1],k)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};