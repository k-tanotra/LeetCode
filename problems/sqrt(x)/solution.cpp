class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = INT_MAX;
        while(start<=end){
            int mid = (end-start)/2 + start;
            if( long(mid)*mid > long(x)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start-1;
    }
};