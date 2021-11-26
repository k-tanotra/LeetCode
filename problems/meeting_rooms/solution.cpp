class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
        // if(a[0]<b[0]){
        //     return true;
        // }
        // else if(a[0]==b[0]){
        //     if(a[1]<b[1]){
        //         return true;
        //     }
        // }
        // return false;
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<"->";
        // }
        // cout<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[i-1][1]){
                return false;
            }
        }
        return true;
    }
};