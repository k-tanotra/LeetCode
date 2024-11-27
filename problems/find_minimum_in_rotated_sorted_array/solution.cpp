class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int candidate = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]<=nums[end]){
                candidate = min(nums[mid],candidate);
                end = end - 1;
            }
            else{
                start = start + 1;
            }
        }
        return candidate;
    }
};