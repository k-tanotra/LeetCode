class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        int res = nums[0] ^ 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            res ^= nums[i]^i;
        }
        return res^n;
        */
        //sum method
        int n = nums.size();
        int reqSum = (n*(n+1))/2;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        
        return reqSum-sum;
    }
};