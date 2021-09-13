class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int high = len-1;
        bool even;
        int ans;
        
        if(len<2){
            return nums[0];
        }
        
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        else if(nums[len-1]!=nums[len-2]){
            return nums[len-1];
        }
        
        while(high>=low){
            int mid = (low + high)/2;
            even = true;
            if(mid%2!=0){
                even = false;
            }
            if((even && nums[mid]==nums[mid+1]) || (!even && nums[mid]==nums[mid-1])){
                 low = mid+1;
            }
            else if((even && nums[mid]==nums[mid-1]) || (!even && nums[mid]==nums[mid+1])) {
                 high = mid;
            }
            else{
                ans = nums[mid];
                break;
            }
        }
        
        return ans;
    }
};