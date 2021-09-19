class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        
        vector< vector<bool> > dp(len2+1, vector<bool>(len1+1,false));
        dp[0][0] = true;
        for(int i=2;i<=len2;i++){
            if(p[i-1]=='*'){
                dp[i][0]=dp[i-2][0];
            }
        }
        
        for(int i=1;i<=len2;i++){
            for(int j=1;j<=len1;j++){
                
                if(p[i-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    if(dp[i-2][j]==true){
                        dp[i][j] = true;
                    }
                    else if(s[j-1]==p[i-2] || p[i-2]=='.'){
                        dp[i][j] = dp[i][j-1];
                    }
                }
                else{
                    if(s[j-1]==p[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        
        return dp[len2][len1];
        
    }
};