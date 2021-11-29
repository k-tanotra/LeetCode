class Solution {
public:
    static bool func(pair<int,int> &a,pair<int,int> &b){
        if(b.second > a.second){
            return false;
        }
        else if(a.second==b.second){
            if(a.first > b.first){
                return false;
            }
        }
        return true;
    }
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            if(a[1]>b[1]){
                return true;
            }
        }
        return false;
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
         if(intervals.size()==1){
            return 1;
        }
        sort(intervals.begin(),intervals.end(),cmp);
        // for(int i=0;i<intervals.size();i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<" || ";
        // }
        int ans = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>> , function<bool(pair<int,int> &,pair<int,int> &)> > pq(func);
        
        // for(int i=0;i<intervals.size();i++){
        //     pq.push({intervals[i][0],intervals[i][1]});
        // }
        // // cout<<endl;
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<" || ";
        //     pq.pop();
        // }
        int res = 1;
        // cout<<endl;
        for(int i=0;i<intervals.size();i++){
            if(pq.empty() || intervals[i][0] < pq.top().second){
                pq.push({intervals[i][0],intervals[i][1]});
                ans++;
            }
            else if(intervals[i][0]>= pq.top().second){
                
                while(!pq.empty() && intervals[i][0]>= pq.top().second){
                    pq.pop();
                    ans--;
                }
                pq.push({intervals[i][0],intervals[i][1]});
                ans++;
            }
            // if(pq.size()>ans){
            //     ans = pq.size();
            // }
            res = max(ans,res);
            // cout<<ans<<endl;
        }
        return res;
    }
};