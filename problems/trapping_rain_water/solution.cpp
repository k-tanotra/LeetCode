class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int mxLeft = INT_MIN;
        int mxRight = INT_MIN;
        int ans = 0;
        while(start<end){
            mxLeft = max(height[start],mxLeft);
            mxRight = max(height[end],mxRight);
            if(height[start]<min(mxLeft,mxRight)){
                ans+= min(mxLeft,mxRight) - height[start];
            }
            else if(height[end]<min(mxLeft,mxRight)){
                ans += min(mxLeft,mxRight) - height[end];
            }
            
            if(height[start]<=height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        
        return ans;
    }
};