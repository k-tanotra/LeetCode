class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<pair<int,int>> alpha(26,{-1,-1});
        vector<int> freq(26,0);
        int lastFreq = -1;
        for(int i= 0;i<s.size();i++){
            freq[s[i]-'a']++;
            alpha[s[i]-'a'] = {i,s[i]-'a'};
            if(lastFreq<freq[s[i]-'a']){
                lastFreq = freq[s[i]-'a'];
            }
        }
        sort(alpha.begin(),alpha.end());
        for(int i=0;i<alpha.size();i++){
            //cout<<freq[i]<<endl;
            //cout<<alpha[i].first<<" "<<alpha[i].second<<endl;
        }
        //cout<<lastFreq;
        string ans = "";
        for(int i=0;i<alpha.size();i++){
            if(alpha[i].second<0){
                continue;
            }
            if(freq[alpha[i].second]==lastFreq){
                ans += 'a'+ alpha[i].second;
            }
        }
        return ans;
    }
};