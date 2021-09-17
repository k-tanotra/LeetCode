class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len =  intervals.size();
        vector<vector<int>> ans;
        
        if(len==0){
            ans.push_back(newInterval);
            return ans;
        }
        int low = 0;
        int high = len-1;
        int mid;
        while(high>=low){
            // cout<<mid<<endl;
            mid= (high+low)/2;
            if(intervals[mid][0]<newInterval[0]){
                low = mid+1;
            }
            else if(intervals[mid][0]>newInterval[0]){
                high = mid-1;
            }
            else{
                break;
            }
        }
        
        if(intervals[mid][0]<newInterval[0]){
            intervals.insert(intervals.begin()+mid+1,newInterval);
        }
        else if(intervals[mid][0]>newInterval[0]){
            intervals.insert(intervals.begin()+mid,newInterval);
        }
        else if(intervals[mid][1]>newInterval[1]){
            intervals.insert(intervals.begin()+mid,newInterval);
        }
        else{
            intervals.insert(intervals.begin()+mid+1,newInterval);
        }
        
        int j =0;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[j][1]>=intervals[i][0]){
                if(intervals[j][1]<intervals[i][1]){
                    intervals[j][1] = intervals[i][1];
                    ans[j][1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
    
        return ans;
        //see if mid is an overlap;
        //see if by moving forward if we find an overlap
    }
};