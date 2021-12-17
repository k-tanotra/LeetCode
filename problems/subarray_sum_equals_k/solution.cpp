class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cml = 0;
        int ans = 0;
        unordered_map<int,int> m;
        m.insert({0,1});
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cml += nums[i];
            if(m.find(sum-k)!=m.end()){
                ans += m[sum-k];
            }
            if(m.find(cml)==m.end()){
                m.insert({cml,1});
            }
            else{
                m[cml]++;
            }
        }
        return ans;
    }
};