class Solution {
public:
    vector<int> dp;
//     void dfs(vector<bool> &dp,int idx,vector<vector<int>>& isConnected){
//         dp[idx] = true;
//         for(int i=0;i<dp.size();i++){
//             if(i!=idx && !dp[i] && isConnected[idx][i]){
//                 dfs(dp,i,isConnected);
//             }
//         }
//     }
    int find_parent(int n){
        if(n==dp[n])
            return n;
        
        return find_parent(dp[n]);
    }
    void uf(int i,int j){
        int a = find_parent(i);
        int b = find_parent(j);
        
        dp[b] = a;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<bool> dp(n,false);
//         int count = 0;
//         for(int i=0;i<n;i++){
//            if(!dp[i]){
//                dfs(dp,i,isConnected);
//                count++;
//            }
//         }
        
//         return count;
        
        
        //TRY 2 UNION FIND
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            dp.push_back(i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j])
                    uf(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==i){
                ans++;
            }
        }
        
        return ans;
    }
};