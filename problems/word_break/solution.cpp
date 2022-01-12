class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
    bool rec(string s,int idx,int n){
        if(idx>=n){
            return true;
        }
        if(dp[idx]==-1){
            string temp = "";
            for(int i=idx;i<n;i++){
                temp +=s[i];
                //cout<<temp<<endl;
                if(st.find(temp)!=st.end() && rec(s,i+1,n)){
                   dp[idx] = true;
                   break;
                }
            }
            if(dp[idx]!=1)
                dp[idx] = false;
        }
        return dp[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            st.insert({wordDict[i]});
        }
        int n = s.length();
        dp.resize(n,-1);
        return rec(s,0,n);
    }
};