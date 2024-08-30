class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int e = 0;
        int d = 0;
        bool t = true;
        while(t){
            while(e>=numExchange){
                e-=numExchange;
                numBottles+=1;
                numExchange+=1;
            }
            d += numBottles;
            e += numBottles;
            numBottles = 0;
            if(e<numExchange){
                t = false;
            }
        }
        return d;
    }
};