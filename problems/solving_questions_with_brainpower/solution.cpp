class Solution {
public:
    vector<long long> dp;
    long long rec(vector<vector<int>>& questions,int n,int idx){
        if(idx>=n){
            return 0;
        }
        //cout<<idx<<endl;
        if(dp[idx]==-1){
            dp[idx] = max(rec(questions,n,idx+questions[idx][1]+1)+questions[idx][0],rec(questions,n,idx+1));
        }
        return dp[idx];
    }
    void print(vector<int> x){
        for(int n:x){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n,-1);
       // int x = rec(questions,n,0);
        //print(dp);
        return rec(questions,n,0);
    }
};