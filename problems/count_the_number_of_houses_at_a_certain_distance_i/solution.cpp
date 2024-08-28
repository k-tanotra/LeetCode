class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
       vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
       for(int i=0;i<n;i++){
         vector<bool> visited(n,false);
         queue<pair<int,int>> q;
         q.push({i,0});
         while(!q.empty()){
            int a = q.front().first;
            int d = q.front().second;
            if(visited[a]){
                q.pop();
                continue;
            }
            q.pop();
            visited[a] = true;
            dp[i][a] = min(dp[i][a],d);
            if(a==x-1 && !visited[y-1]){
                q.push({y-1,d+1});
            }
            if(a==y-1 && !visited[x-1]){
                q.push({x-1,d+1});
            }
            if(a-1>=0 && !visited[a-1]){
                q.push({a-1,d+1});
            }
            if(a+1<n && !visited[a+1]){
                q.push({a+1,d+1});
            }
         }
       }
       vector<int> freq(n,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout<<dp[i][j]<<" ";
            freq[dp[i][j]]++;
        }
        //cout<<endl;
       }
       vector<int> ans;
       for(int i=1;i<n;i++){
            ans.push_back(freq[i]);
       }
       ans.push_back(0);
       return ans;
    }
};