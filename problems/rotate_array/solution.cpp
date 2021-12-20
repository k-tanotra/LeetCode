class Solution {
public:
    void rev(vector<int> &nums,int start,int end){
        while(start<=end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        } 
    }
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){
            k = k%nums.size();
        }
        if(k==0){
            return;
        }
        rev(nums,0,nums.size()-1);
        rev(nums,0,k-1);
        rev(nums,k,nums.size()-1);
    }
};