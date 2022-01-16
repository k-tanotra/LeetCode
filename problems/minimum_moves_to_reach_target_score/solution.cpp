class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(target!=1){
            if(target%2==0){
                if(maxDoubles>0){
                    target = target/2;
                    maxDoubles--;
                    moves++;
                }
                else{
                    moves += target-1;
                    target = 1;
                }
            }
            else{
                if(maxDoubles==0){
                    moves += target-1;
                    target = 1;
                }
                else{
                    moves++;
                    target--;
                }
            }
        }
        
        return moves;
    }
};