class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            pq.push(abs(queries[i][0])+abs(queries[i][1]));
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()<k){
                ans.push_back(-1);
            }
            if(pq.size()==k){
                int x = pq.top();
                ans.push_back(x);
            }
        }
        return ans;
    }
};