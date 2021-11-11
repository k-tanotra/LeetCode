class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(b[0]>a[0]){
            return true;
        }
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        ans.push_back(intervals[0]);
        int idx = 0;
        for(int i=1;i<intervals.size();i++){
            // cout<<intervals[i][0]<<"--"<<intervals[i][1]<<" || "<<ans[idx][0]<<"--"<<ans[idx][1]<<endl;
            if(intervals[i][0]>=ans[idx][0] && intervals[i][0]<=ans[idx][1]){
                if(intervals[i][1]>ans[idx][1]){
                    ans[idx][1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
                idx++;
            }
        }
        
        return ans;
    }
};