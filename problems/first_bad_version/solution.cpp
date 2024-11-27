// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int found;
        while(start<=end){
            int mid = (end-start)/2 + start;
            if(isBadVersion(mid)){
                found = mid;
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        return found;
    }
};