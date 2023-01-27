class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num!=0){
            if(num&1==1){
                count++;
                num-=1;
            }
            if(num!=0){
                count++;
                num = num>>1;
            }
        }
        return count;
    }
};