class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket  sort O(n)
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto itr=m.begin();itr!=m.end();itr++){
            buckets[itr->second].push_back(itr->first);
        }
        
        vector<int> ans;
        int sz = 0;
        for(int i=buckets.size()-1;i>=0 && sz!=k;i--){
            for(int j=0;j<buckets[i].size() && sz!=k;j++){
                ans.push_back(buckets[i][j]);
                sz++;
            }
        }
        return ans;
    }
};