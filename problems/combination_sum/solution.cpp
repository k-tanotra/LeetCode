class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1,vector<vector<int>>());
        dp[0].push_back(vector<int>());
        
        for(int i=0;i<candidates.size();i++){
            for(int j=1;j<=target;j++){
                if(candidates[i]<=j){
                    vector<vector<int>> x = dp[j-candidates[i]];
                    // for(int p=0;p<x.size();p++){
                    //     for(int q=0;q<x[p].size();q++){
                    //         cout<<x[p][q]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    // cout<<"NEXT--"<<j-candidates[i]<<" "<<dp[j-candidates[i]].size()<<endl;
                    for(int k=0;k<x.size();k++){
                        vector<int> y = dp[j-candidates[i]][k];
                        y.push_back(candidates[i]);
                        dp[j].push_back(y);
                    }
                }
            }
        }
       
        // for(int i=0;i<dp.size();i++){
        //     cout<<i<<endl;
        //     for(int j=0;j<dp[i].size();j++){
        //         for(int k=0;k<dp[i][j].size();k++){
        //             cout<<dp[i][j][k]<<" ";
        //         }
        //         cout<<"--";
        //     }
        //     cout<<endl;
        // }
        
        return dp[target];
    }
};