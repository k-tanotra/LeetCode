class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        unordered_map<int,int> r;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end())
                m.insert({nums[i],i});
            else{
                if(r.find(nums[i])==r.end()){
                     r.insert({nums[i],i});
                }
            }
        }
        vector<int> ans;
        int k = target;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(k-itr->first!=itr->first && m.find(k-itr->first)!=m.end()){
                ans.push_back(itr->second);
                ans.push_back(m[k-itr->first]);
                return ans;
            }
            else if(k-itr->first==itr->first && m.find(k-itr->first)!=m.end() && r.find(itr->first)!=r.end()){
                ans.push_back(itr->second);
                ans.push_back(r[k-itr->first]);
                return ans;
            }
        }
        return ans;
    }
};