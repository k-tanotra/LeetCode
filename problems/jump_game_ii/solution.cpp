class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int far_max = 0;
        int cur_max = 0;
        int ans = 0;
        for(int i=0;i<len-1;i++){
            cur_max = max(cur_max,i+nums[i]);
            if(i>=far_max){
                far_max = cur_max;
                ans++;
            }
        }
        
        return ans;
    }
};