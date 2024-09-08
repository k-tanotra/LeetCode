class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        int last = 0;
        for(int i=1;i<nums.size();i++){
            long long temp = (long long)nums[last]*(i-last);
            if(i==nums.size()-1){
                score += temp;
                continue;
            }
            if(nums[last] <= nums[i]){
                last = i;
                score += temp;
            }
        }
        return score;
    }
};