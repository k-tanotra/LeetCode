class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = INT_MIN;
        int sum = 0;
        int cur = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cur = cur + nums[i];
            cur<0 ? cur = 0 : sum = max(sum,cur); 
           if(nums[i]<0){
               mn = max(nums[i],mn);
               cnt++;
           }
        }
        
        if(cnt==nums.size())
            return mn;
        else
            return sum;
    }
};