class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int front = 1;
        int back = 1;
        for(int i=0;i<n;i++){
              ans[i] *= front;
              front *= nums[i];
              ans[n-i-1] *= back;
              back *=nums[n-i-1];
        }
        return ans;
    }
};