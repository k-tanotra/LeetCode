class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n+2,0);
        long long op = 0;
        for(int i=0;i<n;i++){
            diff[i+1] = target[i] - nums[i];
        }
        for(int i=0;i<diff.size()-1;i++){
            op += abs(diff[i+1] - diff[i]);
        }
        return op/2;
    }
};