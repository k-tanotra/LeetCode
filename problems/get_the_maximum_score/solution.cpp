class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int top = 0;
        int bottom = 0;
        long long sum = 0;
        long long runningSumTop = 0;
        long long runningSumBottom = 0;
        int MOD = 1000000007;
        while(top<nums1.size() || bottom<nums2.size()){
            if(top<nums1.size() && bottom<nums2.size()){
                if(nums1[top]<nums2[bottom]){
                    runningSumTop += nums1[top];
                    top++;
                }
                else if(nums1[top]>nums2[bottom]){
                    runningSumBottom += nums2[bottom];
                    bottom++;
                }
                else{
                    sum += max(runningSumTop,runningSumBottom);
                    runningSumTop = nums1[top];
                    runningSumBottom = nums2[bottom];
                    top++;
                    bottom++;
                }
            }
            else if(top<nums1.size()){
                runningSumTop += nums1[top];
                top++;
            }  
            else if(bottom<nums2.size()){
                runningSumBottom += nums2[bottom];
                bottom++;
            }
        }

        sum += max(runningSumTop,runningSumBottom);
        return sum%MOD;
    }
};