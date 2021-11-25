class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m.insert({nums[i],1});
            }
            else{
                m[nums[i]]++;
            }
        }
        priority_queue<pair<int,int>> pq;
        for(auto itr=m.begin();itr!=m.end();itr++){
            pq.push({itr->second,itr->first});
        }
        
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};