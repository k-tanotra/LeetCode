class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         for(int i=0;i<k;i++){
             int mn =nums[0];
             int idx = 0;
             for(int i=0;i<nums.size();i++){
                if(mn>nums[i]){
                    mn = nums[i];
                    idx = i;
                }
            }
            nums[idx] = multiplier*nums[idx];
         }
        return nums;
    }
};