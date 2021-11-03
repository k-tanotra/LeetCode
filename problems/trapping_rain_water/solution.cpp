class Solution {
public:
    int trap(vector<int>& height) {
        int mx = 0;
        int start = 0;
        int end = height.size()-1;
        int ans = 0;
        while(start<end){
            int cur_min = min(height[start],height[end]);
            cur_min<mx ? ans+=mx-cur_min : mx=cur_min;
            height[start]<=height[end] ? start++ : end--;
        }
        return ans;
    }
};