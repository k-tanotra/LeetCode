class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int last = nums.size()-1;
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            if(abs(nums[end])>=abs(nums[start])){
                ans[last] = nums[end]*nums[end];
                end--;
            }
            else{
                ans[last] = nums[start]*nums[start];
                start++;
            }
            last--;
        }
        return ans;    
    }
};