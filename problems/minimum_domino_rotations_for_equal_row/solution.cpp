class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> tm(6,0);
        vector<int> bm(6,0);
        vector<int> sim(6,0);
        
        for(int i=0;i<n;i++){
            if(tops[i]!=bottoms[i]){
                tm[tops[i]-1]++;
                bm[bottoms[i]-1]++;
            }
            else{
                sim[tops[i]-1]++;
            }
        }
        int moves = INT_MAX;
        for(int i=0;i<6;i++){
            if(tm[i]+bm[i]+sim[i]==n){
                moves = min(moves,min(tm[i],bm[i]));
            }
        }
        if(moves==INT_MAX){
            return -1;
        }
        return moves;
    }
};