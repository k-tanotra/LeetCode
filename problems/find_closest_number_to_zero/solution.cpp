class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX;
        int ans;

        for(int i=0;i<nums.size();i++){
            if(dist>abs(nums[i])){
                ans = nums[i];
                dist = abs(nums[i]);
            }
            if(dist==abs(nums[i])){
                ans = max(ans,nums[i]);
            }
        }

        return ans;
    }
};