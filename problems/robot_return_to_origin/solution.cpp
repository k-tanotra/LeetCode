class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0;
        int left=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                up++;
            }
            else if(moves[i]=='D'){
                up--;
            }
            else if(moves[i]=='L'){
                left++;
            }
            else if(moves[i]=='R'){
                left--;
            }
        }
        return (up==0 && left==0);
    }
};