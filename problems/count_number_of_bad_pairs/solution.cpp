class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int,int> m;
        long long x = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            x += m[nums[i]-i];
            m[nums[i]-i]++;
        }
        long long pairs = ((sz-1)*1ll*sz)/2;
        return pairs-x;
    }
};