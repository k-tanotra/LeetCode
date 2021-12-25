class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int ans = -1;
        while(j<n){
            if(m.find(nums[j])==m.end()){
                m.insert({nums[j],j});
            }
            else{
                int t = m[nums[j]];
                for(int k=i;k<=m[nums[j]];k++){
                    sum-=nums[k];   
                    m.erase(nums[k]);
                }
                i = t+1;
                m[nums[j]] = j;
            }
            sum += nums[j];
            ans = max(ans,sum);
            j++;
        }
        
        return ans;
    }
};