class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        
        sort(cuboids.begin(),cuboids.end());
        /*
        for(int i=0;i<cuboids.size();i++){
            for(int j=0;j<cuboids[i].size();j++){
                cout<<cuboids[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        int n = cuboids.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[j][1]<=cuboids[i][1] && cuboids[j][2]<=cuboids[i][2]){
                    dp[i] = max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};