class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int len = candiesCount.size();
        vector<bool> ans;
        vector<long long> sums(len+1,0);
        
        sums[0] = 0;
        for(int i=1;i<=len;i++){
            sums[i] = candiesCount[i-1] + sums[i-1]; 
        }
        
        for(int i=0;i<queries.size();i++){
            if(queries[i][1]+1>sums[queries[i][0] + 1]){
                ans.push_back(false);
                continue;
            }
            else{
                long long a = sums[queries[i][0]]/queries[i][2];
                long long b = sums[queries[i][0]]%queries[i][2];
                if(b==0){
                    if(queries[i][1]+1<=a){
                        ans.push_back(false);
                        continue;
                    }
                }
                else{
                    a=a+1;
                    if(queries[i][1]+1<a){
                        ans.push_back(false);
                        continue;
                    }
                }
            }
            ans.push_back(true);
        }
        
        return ans;
    }
};