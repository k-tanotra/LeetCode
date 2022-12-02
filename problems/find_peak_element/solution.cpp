class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int sz = nums.size()-1;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (end - start)/2 + start;
            if(mid!=sz && nums[mid]<=nums[mid+1]){
                start = mid+1;
            }
            else if(mid!=0 && nums[mid]<=nums[mid-1]){
                end = mid-1;
            }
            else if( (mid==0 && nums[mid+1]<nums[mid]) || ((mid==sz && nums[mid-1]<nums[mid]))
                    || (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) ){
                return mid;
            }
        }
        return start;
    }
};