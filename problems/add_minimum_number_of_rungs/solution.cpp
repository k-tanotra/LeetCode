class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int start = 0;
        int mx = 0;
        int count = 0;
        for(int i=0;i<rungs.size();i++){
           if (mx + dist < rungs[i]) {
                int rungs_needed = ceil((rungs[i] - mx) / (double)dist) - 1;
                count += rungs_needed;
                mx = mx + rungs_needed * dist;
            }
            mx = rungs[i];
        }
        return count;
    }
};