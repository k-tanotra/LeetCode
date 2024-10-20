class Solution {
public:
    int getGPD(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return n / i;
            }
        }
        return 1;
    }
    int minOperations(vector<int>& nums) {
       int cnt = 0;
       for(int i=nums.size()-2;i>=0;i--){
            while(nums[i+1]<nums[i]){
                int x = getGPD(nums[i]);
                if(x==1){
                    return -1;
                }
                else{
                    cnt++;
                    nums[i] = nums[i]/x;
                }
            }
       }
       return cnt;
    }
};