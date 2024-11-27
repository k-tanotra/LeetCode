class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0]^0;
        for(int i=1;i<nums.size();i++){
            x ^= nums[i];
            x ^= i;
        }
        x^=n;
        return x;
    }
};