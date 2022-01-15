class Solution {
public:
    void print(vector<vector<int>> arr){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0){
            return "";
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            dp[i][1] = 1;
        }
        int start = 2;
        int ans = 1;
        int sIdx = 0;
        for(int i=2;i<=n;i++,start++){
            for(int j=start;j<=n;j++){
                if(s[j-1]==s[j-i]){
                    dp[j][i] = dp[j-1][i-2] || i==2 ? dp[j-1][i-2] + 2:0;
                    if(dp[j][i]>ans){
                        ans = dp[j][i];
                        sIdx = j-i;
                    }
                }
            }
        }
        return s.substr(sIdx,ans);
    }
};