class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int len = arr.size();
        int high = len-1;
        int low = 0;
        int mid;
        int ans = INT_MAX;
        
        while(high>=low){
            mid = (high + low)/2;
            if(arr[mid]>mid){
                high = mid-1;
            }
            else if((arr[mid]<mid) || arr[mid]<0){
                low = mid+1;
            }
            else{
                ans = min(ans,mid);
                high = mid-1;
            }
        }
        
        if(ans!=INT_MAX){
            return ans;
        }
        else
            return -1;
    }
};