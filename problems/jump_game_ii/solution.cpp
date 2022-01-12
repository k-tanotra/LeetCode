class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int nextStop = 0;
        int mx = 0;
        int n = nums.size();
        for(int i=0;i<n && nextStop<n-1;i++){
            mx = max(mx,nums[i]+i);
            if(i==nextStop){
                jumps++;
                nextStop = mx;
            }
        }
        return jumps;
    }
};