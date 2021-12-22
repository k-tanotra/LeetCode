class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<vector<string>> dp(n+1,vector<string>());
       dp[1] = vector<string>(1,"()");
       unordered_set<string> st;
       st.insert("()");
      // string s;
       for(int i=2;i<=n;i++){
           for(int j=1;j<i;j++){
               //vector<string> x = dp[j];
               //vector<string> y = dp[i-j];
               for(int p=0;p<dp[j].size();p++){
                   for(int q=0;q<dp[i-j].size();q++){
                       //s = dp[j][p] + dp[i-j][q];
                       if(st.find(dp[j][p] + dp[i-j][q])==st.end()){
                           st.insert(dp[j][p] + dp[i-j][q]);
                           dp[i].push_back(dp[j][p] + dp[i-j][q]);
                       }
                   }
                   if(j==i-1){
                       //s = "(" + dp[j][p] + ")";
                       dp[i].push_back("(" + dp[j][p] + ")");
                   }
               }
           }
       }
        
       return dp[n];
    }
};