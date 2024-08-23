class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums[0].size();i++){
            s.insert(nums[0][i]);
        }
        for(int i=1;i<nums.size();i++){
            unordered_set<int> s2;
            for(int j=0;j<nums[i].size();j++){
                s2.insert(nums[i][j]);
            }
            unordered_set<int> s3;
            for(auto itr=s.begin();itr!=s.end();itr++){
                if(s2.find(*itr)!=s2.end()){
                    s3.insert(*itr);
                }
            }
            s = s3;
        }
        vector<int> ans;
        for(auto itr=s.begin();itr!=s.end();itr++){
            ans.push_back(*itr);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};