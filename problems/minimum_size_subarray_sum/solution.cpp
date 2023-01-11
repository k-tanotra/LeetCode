class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int res = nums.size()+1;
        for(int end=0;end<nums.size();end++){
            target -= nums[end];
            while(start<nums.size() && target<=0){
                res = min(res,end-start+1);
                target += nums[start];
                start++;
            }
        }
        return res % (nums.size()+1);
    }
};