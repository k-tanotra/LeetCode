class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        long long ans = 0;
        while(start<=end){
            if(start==end){
                ans += nums[start];
            }
            else{
                string x = to_string(nums[start]);
                string y = to_string(nums[end]);
                x = x + y;
                int z = stoi(x);
                ans += z;
            }
            start++;
            end--;
        }
        return ans;
    }
};