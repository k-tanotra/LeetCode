class Solution {
public:
    void print(vector<int> &dp){
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        vector<int> p1(n,0);
        vector<int> p2(n,0);

        for(int i=0;i<n;i++){
            p1[i] = max(values[i]+i,p1[i]);
            p2[i] = values[i]-i;
        }

        for(int i=n-2;i>=0;i--){
            p2[i] = max(p2[i],p2[i+1]);
        }

        //print(p1);
        //print(p2);

        int ans = INT_MIN;
        for(int i=0;i<n-1;i++){
            ans = max(ans,p1[i]+p2[i+1]);
        }
        return ans;
        
    }
};