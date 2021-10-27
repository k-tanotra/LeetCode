class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> d1(n,0);
        vector<int> d2(n,0);
        int m = INT_MIN;
        int mx = INT_MAX;
        for(int i=0;i<n;i++){
            m = max(m,nums[i]);
            d1[i] = m;
        }
        
        for(int i=n-1;i>=0;i--){
            mx = min(mx,nums[i]);
            d2[i] = mx;
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(d1[i-1]<nums[i] && nums[i]<d2[i+1]){
                ans+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                ans+=1;
            }
        }
        
        return ans;
    }
};