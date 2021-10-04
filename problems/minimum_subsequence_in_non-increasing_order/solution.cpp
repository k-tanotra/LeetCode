class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        long long sum = 0;
        for(int num:nums){
            sum = sum + num;
        }
        long long sum2 = 0;
        for(int i=nums.size()-1;i>=0;i--){
            sum2 = sum2  + nums[i];
            sum  = sum - nums[i];
            ans.push_back(nums[i]);
            if(sum2>sum){
                break;
            }
        }
        
        return ans;
    }
};