class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int n = machines.size();
        for(int i=0;i<machines.size();i++){
            sum+= machines[i];
        }
        if(sum%n!=0){
            return -1;
        }
        int all = sum/n;
        int moves = 0;
        sum  =0;
        for(int i=0;i<n;i++){
            sum += machines[i]-all;
            moves= max(moves,max(machines[i]-all,abs(sum)));
        }
        return moves;
    }
};