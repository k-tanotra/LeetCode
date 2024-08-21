class Solution {
public:
    int minChanges(int n, int k) {
        int changes = 0;
        while(n>0){
            int x = n & 1;
            int y = k & 1;
            if(x==1 && y!=1){
                changes++;
            }
            if(x==0 && y==1){
                return -1;
            }
            n = n/2;
            k = k/2;
        }
        if(k!=0){
            return -1;
        }
        return changes;
    }
};
// 1101 - 13
// 1110 - 14