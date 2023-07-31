class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool used = false;
        for(int i=0;i<intervals.size();i++){
           if(intervals[i][0]>newInterval[1] && !used){
               ans.push_back(newInterval);
               used = true;
           }
           else if(intervals[i][1]>=newInterval[0] && !used){
               intervals[i][0] = min(intervals[i][0],newInterval[0]);
               intervals[i][1] = max(intervals[i][1],newInterval[1]);
               used = true;
           }
           if(!ans.empty() && ans.back()[1]>=intervals[i][0]){
               ans.back()[0] = min(ans.back()[0],intervals[i][0]);
               ans.back()[1] = max(ans.back()[1],intervals[i][1]);
           }
           else{
               ans.push_back(intervals[i]);
           }
        }
        if(!used){
            ans.push_back(newInterval);
        }
        return ans;
    }
};