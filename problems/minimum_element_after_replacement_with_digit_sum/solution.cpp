class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            while(nums[i]>0){
                sum += nums[i]%10;
                nums[i] = nums[i]/10;
            }
            if(sum<mn){
                mn = sum;
            }
            nums[i] = sum;
        }
        return mn;
    }
};