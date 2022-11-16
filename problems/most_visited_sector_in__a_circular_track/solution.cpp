class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int len = rounds.size();
        for(int i=rounds[0];i<=rounds[len-1];i++){
            res.push_back(i);
        }
        if(res.size()>0){
            return res;
        }
        for(int i=1;i<=rounds[len-1];i++){
            res.push_back(i);
        }
        for(int i=rounds[0];i<=n;i++){
            res.push_back(i);
        }
        return res;
    }
};