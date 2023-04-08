class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int flips = k;
        int mx = 0;
        while(end<nums.size()){
           if(nums[end] == 0) {
            flips--;
            }
            while(flips < 0) {
                if(nums[start] == 0) {
                    flips++;
                }
                start++;
            }
           mx = max(mx,end-start+1);
           end++;
        }
        return mx;
    }
};