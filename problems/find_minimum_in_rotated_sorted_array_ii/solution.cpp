class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int candidate = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            candidate = min(nums[mid],candidate);
            if(nums[start]==nums[mid] && nums[end]==nums[mid]){
                start++;
                end--;
            }
            else if(nums[mid]<=nums[end]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return candidate;
    }
};