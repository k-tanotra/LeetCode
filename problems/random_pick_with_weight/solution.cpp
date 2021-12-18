class Solution {
public:
    vector<int> ans;
    Solution(vector<int>& w) {
        int cml = 0;
        for(int i=0;i<w.size();i++){
            ans.push_back(cml+w[i]);
            cml +=w[i];
        }
    }
    int pickIndex() {
        return upper_bound(ans.begin(),ans.end(),rand() % ans.back()) - ans.begin();    
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */