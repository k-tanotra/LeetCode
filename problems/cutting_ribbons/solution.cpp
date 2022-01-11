class Solution {
public:
    bool check(int mid,vector<int> &ribbons,int k){
        int sum = 0;
        for(int i=0;i<ribbons.size();i++){
            sum += ribbons[i]/mid;
        }
        if(sum>=k)
            return true;
        return false;
    }
    int maxLength(vector<int>& ribbons, int k) {
        
        int mx = INT_MIN;
        for(int i=0;i<ribbons.size();i++){
            mx = max(mx,ribbons[i]);
        }
        
        int start = 1;
        int end = mx;
        int lastFound = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(mid,ribbons,k)){
                lastFound = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return lastFound==-1? 0 : lastFound;
    }
};