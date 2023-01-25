class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        int sum2 = 0;
        int ans = INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            sum2 += (i>=nums.size()-1? 0 : nums[i+1]);
            sum -= nums[i];
            if(sum==sum2){
                ans = min(ans,i);
            }
        }

        return ans==INT_MAX ? -1: ans;
    }
};