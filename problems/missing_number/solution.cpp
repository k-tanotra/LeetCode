class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums[0] ^ 0;
        for(int i=1;i<nums.size();i++){
            x ^= nums[i]^i;
        }
        x=x^(nums.size());
        return x;
    }
};