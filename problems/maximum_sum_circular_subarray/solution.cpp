class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curMin = 0;
        int curMax = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            curMax = max(curMax+nums[i],nums[i]);
            mx= max(curMax,mx);
            curMin = min(curMin+nums[i],nums[i]);
            mn = min(curMin,mn);
        }
        
        return mx>0 ? max(mx,total-mn) : mx;
    }
};