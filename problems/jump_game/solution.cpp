class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];
        for(int i=1;i<=maxIndex && i<nums.size();i++){
            if(nums[i]+i>maxIndex){
                maxIndex = nums[i]+i;
            }
        }
        return (maxIndex>=nums.size()-1);
    }
};