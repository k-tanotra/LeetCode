class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m.insert({nums[i]});
            }
        }
        if(nums.size()<1){
            return 0;
        }
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)==m.end()){
                int a = nums[i];
                int count = 0;
                while(m.find(a)!=m.end()){
                    count++;
                    a = a + 1;
                }
                ans = max(count,ans);
            }
        }
        
        return ans;
    }
};