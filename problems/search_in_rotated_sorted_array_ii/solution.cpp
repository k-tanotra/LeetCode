class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]==nums[end] && nums[start]==nums[end]){
                start++;
                end--;
            }
            else if(nums[mid]<=nums[end]){
                if(nums[mid]<target && target<=nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            else{
                if(nums[mid]<target && target>=nums[end]){
                    start = mid + 1;
                }
                else if(nums[mid]>target && target>nums[end]){
                    end = mid - 1;
                }
                else if(nums[mid]>target && target<=nums[end]){
                    start = start + 1;
                }
            }
        }
        return false;
    }
};