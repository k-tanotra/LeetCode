class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int start = 0;
        int end = 0;
        while(end<n){
            while(end+1<n && nums[end]!=nums[end+1]){
                end++;
            }
            long long len = (end-start+1);
            ans += ((len+1) * len)/2;
            start=end+1;
            end = start;
        }
        return ans;
    }
};