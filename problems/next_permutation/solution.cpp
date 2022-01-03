class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int firstDec = INT_MAX;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                firstDec = min(firstDec,i);
                break;
            }
        }
        if(firstDec==INT_MAX){
            reverse(nums.begin(),nums.end());
            return;
        }
        int mn = INT_MAX;
        int swpIdx = -1;
        for(int i=nums.size()-1;i>firstDec;i--){
            if( nums[i]>nums[firstDec]){
                swpIdx = i;
                break;
            }
        }
        swap(nums[swpIdx],nums[firstDec]);
        reverse(nums.begin()+firstDec+1,nums.end());
        return;
    }
};