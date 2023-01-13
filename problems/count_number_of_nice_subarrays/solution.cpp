class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       for(int i=0;i<nums.size();i++){
           nums[i] = nums[i]%2;
       }

       unordered_map<int,int> m;
       m[0] = 1;
       int sum = 0;
       int count = 0;
       for(int i=0;i<nums.size();i++){
           sum += nums[i];
           if(m.find(sum-k)!=m.end()){
               count += m[sum-k];
           }
           m[sum]++;
       }

       return count;
    }
};