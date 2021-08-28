class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        for(int i=0;i<len;i++){
            nums[abs(nums[i])-1] = -1 * abs(nums[abs(nums[i])-1]);
        }
        for(int i=0;i<len;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};