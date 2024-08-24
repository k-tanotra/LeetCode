class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
         vector<int> a;
         vector<int> b;
         for(int i=0;i<flowers.size();i++){
             a.push_back(flowers[i][0]);
             b.push_back(flowers[i][1]);
         }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int> res;
        for(int i=0;i<people.size();i++){
            int x = upper_bound(a.begin(),a.end(),people[i]) - a.begin();
            int y = lower_bound(b.begin(),b.end(),people[i]) - b.begin();
            res.push_back(x-y);
        }
        return res;
    }
};