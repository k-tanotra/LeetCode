class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = mx;
            mx=max(nums[i],max(mx*nums[i],mn*nums[i]));
            mn=min(nums[i],min(temp*nums[i],mn*nums[i]));
            ans = max(mx,ans);
        }
        return ans;
    }
};