class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int left = -1;
        int right = -1;
        int total = 0;
        while(start<=end){
            left = max(left,height[start]);
            right = max(right,height[end]);
            int mn = min(left,right);
            if(height[start]<mn){
                total += mn - height[start];
            }
            if(height[end]<mn && start!=end){
                total += mn - height[end];
            }
            if(left<=right){
                start++;
            }
            else if(right<left){
                end--;
            }
        }
        return total;
    }
};