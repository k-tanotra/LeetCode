class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int runningSum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            runningSum += nums[i];
            if(runningSum==0){
                count++;
            }
        }
        return count;
    }
};