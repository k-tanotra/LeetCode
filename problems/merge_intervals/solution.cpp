class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int lastIdx = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<= ans[lastIdx][1]){
                ans[lastIdx][1] = max(intervals[i][1],ans[lastIdx][1]);
            }
            else{
                ans.push_back(intervals[i]);
                lastIdx++;
            }
        }
        return ans;
    }
};